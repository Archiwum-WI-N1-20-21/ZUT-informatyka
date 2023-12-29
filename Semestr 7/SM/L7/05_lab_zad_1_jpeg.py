import numpy as np
import matplotlib.pyplot as plt
import cv2
import scipy.fftpack
import sys
import humanize


'''Algorytm:
-> obraz wejściowy - wycinek: 128x128 lub 256x256
1. konwersja przestrzeni RGB do YCbCr
2. redukcja chrominancji -> Chroma Subsampling / Chroma Re-sampling, 2 rodzaje 4:4:4 i 4:2:2
3. podział obrazu na bloki 8x8 (każda warstwa przetwarzana jest osobno)
4. Wykonanie dyskretnej transformaty kosinusowej (DCT)
5. Kwantyzacja poprzez zastąpienie wartości zmiennoprzecinkowych, wartościami całkowitymi
   Ewentualne dzielenie przez macierze kwantyzacji w celu zwiększenia kompresji
6. Porządkowanie współczynników DCT w sposób liniowy poprzez zygzakowanie
7. Kompresja bezstratna danych
'''


def dataToBlocks_8x8(data_color):
    data_blocks_8x8 = []
    for row in range(0, data_color.shape[0], 8):
        for col in range(0, data_color.shape[1], 8):
            block = data_color[row:row + 8, col:col + 8]
            data_blocks_8x8.append(block)
    return data_blocks_8x8


def blocks_8x8_ToData(blocks, sizeA, sizeB):
    data = np.zeros((sizeA, sizeB))
    index = 0
    for row in range(0, sizeA, 8):
        for col in range(0, sizeB, 8):
            data[row:row + 8, col:col + 8] = blocks[index]
            index += 1
    return data


def dct2(a):
    return scipy.fftpack.dct(scipy.fftpack.dct(a.astype(float), axis=0, norm='ortho'), axis=1, norm='ortho')


def idct2(a):
    return scipy.fftpack.idct(scipy.fftpack.idct(a.astype(float), axis=0, norm='ortho'), axis=1, norm='ortho')


def quantization(data, q_table):
    quantized = np.zeros((data.shape[0], data.shape[1]))
    index = 0
    for row in range(0, data.shape[0], 8):
        for col in range(0, data.shape[1], 8):
            quantized[index:index+64] = np.round(data/q_table).astype(int)
            index += 64
    return quantized


def dequantization(data, q_table):
    for idx, i in enumerate(range(0, data.shape[0], 8)):
        dequantized = data[i:i + 8] * q_table
    return dequantized


''' Tablica Kwantyzacji dla Luminancji dla jakości 50%: '''
QY = np.array([
        [16, 11, 10, 16, 24,  40,  51,  61],
        [12, 12, 14, 19, 26,  58,  60,  55],
        [14, 13, 16, 24, 40,  57,  69,  56],
        [14, 17, 22, 29, 51,  87,  80,  62],
        [18, 22, 37, 56, 68,  109, 103, 77],
        [24, 36, 55, 64, 81,  104, 113, 92],
        [49, 64, 78, 87, 103, 121, 120, 101],
        [72, 92, 95, 98, 112, 100, 103, 99],
        ])

''' Tablica kwantyzacji dla Chrominancji po redukcji 2:1 dla jakości 50%,
    ale można ją stosować również na pełnej chrominancji: '''
QC = np.array([
        [17, 18, 24, 47, 99, 99, 99, 99],
        [18, 21, 26, 66, 99, 99, 99, 99],
        [24, 26, 56, 99, 99, 99, 99, 99],
        [47, 66, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        ])

''' Tablica jedynek'''
O = np.ones((8, 8))


def zigzag(A):
    template = np.array([
            [0,  1,  5,  6,  14, 15, 27, 28],
            [2,  4,  7,  13, 16, 26, 29, 42],
            [3,  8,  12, 17, 25, 30, 41, 43],
            [9,  11, 18, 24, 31, 40, 44, 53],
            [10, 19, 23, 32, 39, 45, 52, 54],
            [20, 22, 33, 38, 46, 51, 55, 60],
            [21, 34, 37, 47, 50, 56, 59, 61],
            [35, 36, 48, 49, 57, 58, 62, 63],
            ])
    if len(A.shape) == 1:
        B = np.zeros((8, 8))
        for r in range(0, 8):
            for c in range(0, 8):
                B[r, c] = A[template[r, c]]
    else:
        B = np.zeros((64,))
        for r in range(0, 8):
            for c in range(0, 8):
                B[template[r, c]] = A[r, c]
    return B


def chromaSubsampling(data):
    # wariant 4:2:2 - czyli redukujemy co drugą kolumnę
    reduced = np.empty((data.shape[0], int(data.shape[1]/2)))
    for row in range(0, data.shape[0]):
        for col in range(0, data.shape[1], 2):
            reduced[row][int(col/2)] = data[row][col]
    return reduced


def chromaResampling(data):
    # wariant 4:2:2 - czyli redukcja ilości pikseli o 50% w poziomie
    # -> każda wartość będzie odtwarzana za pomocą piksela na lewo od niego
    recreated = np.empty((data.shape[0], data.shape[1]*2))
    for row in range(0, data.shape[0]):
        for col in range(0, data.shape[1]):
            recreated[row][col*2] = data[row][col]
            recreated[row][col*2+1] = data[row][col]
    return recreated


def rle_encode(data):
    data = data.astype(int)
    data_shape = data.shape
    data = data.flatten()
    sign_counter = 0
    previous_sign = None
    coded_stream = []
    for sign in data:
        if sign == previous_sign:
            sign_counter += 1
        else:
            if previous_sign is not None:
                coded_stream.append(sign_counter)
                coded_stream.append(previous_sign)
            sign_counter = 1
            previous_sign = sign
    coded_stream.append(sign_counter)
    coded_stream.append(previous_sign)
    coded_stream = np.array(coded_stream)
    return [data_shape, coded_stream]


def rle_decode(coded_data):
    coded_shape = coded_data[0]
    coded_stream = coded_data[1]
    decoded_stream = []
    for i in range(0, len(coded_stream), 2):
        sign = coded_stream[i + 1]
        sign_counter = coded_stream[i]
        for j in range(sign_counter):
            decoded_stream.append(sign)
    decoded_stream = np.array(decoded_stream)
    decoded_stream = decoded_stream.reshape(coded_shape)
    return decoded_stream


def get_size(obj, seen=None):
    """Recursively finds size of objects"""
    size = sys.getsizeof(obj)
    if seen is None:
        seen = set()
    obj_id = id(obj)
    if obj_id in seen:
        return 0
    # Important mark as seen *before* entering recursion to gracefully handle
    # self-referential objects
    seen.add(obj_id)
    if isinstance(obj, np.ndarray):
        size = obj.nbytes
    elif isinstance(obj, dict):
        size += sum([get_size(v, seen) for v in obj.values()])
        size += sum([get_size(k, seen) for k in obj.keys()])
    elif hasattr(obj, '__dict__'):
        size += get_size(obj.__dict__, seen)
    elif hasattr(obj, '__iter__') and not isinstance(obj, (str, bytes, bytearray)):
        size += sum([get_size(i, seen) for i in obj])
    return size


def get_human_size(size):
    return humanize.naturalsize(size)


def jpeg_compression(img, chroma_type, qt_mode, QY_table=None, QC_table=None, O_table=None):
    """ 1. konwersja przestrzeni RGB do YCbCr
        2. Chroma Subsampling
        3. blokowanie danych - 8x8
        4. bloki 8x8 - DCT
        5. bloki 8x8 - Kwantyzacja
        6. bloki 8x8 - Zygzakowanie -> vector 64 elementowy
        7. Kompresja RLE """
    img_YCrCb = cv2.cvtColor(img, cv2.COLOR_RGB2YCrCb).astype(int)
    Y, Cr, Cb = np.clip(cv2.split(img_YCrCb), 0, 255)

    if chroma_type != "4:4:4":
        Y = chromaSubsampling(Y)
        Cr = chromaSubsampling(Cr)
        Cb = chromaSubsampling(Cb)

    Y_blocks = dataToBlocks_8x8(Y)
    Cr_blocks = dataToBlocks_8x8(Cr)
    Cb_blocks = dataToBlocks_8x8(Cb)

    for i in range(len(Y_blocks)):
        Y_blocks[i] = Y_blocks[i].astype(int) - 128
        Cr_blocks[i] = Cr_blocks[i].astype(int) - 128
        Cb_blocks[i] = Cb_blocks[i].astype(int) - 128

        Y_blocks[i] = dct2(Y_blocks[i])
        Cr_blocks[i] = dct2(Cr_blocks[i])
        Cb_blocks[i] = dct2(Cb_blocks[i])

        if qt_mode:
            Y_blocks[i] = quantization(Y_blocks[i], QY_table)
            Cr_blocks[i] = quantization(Cr_blocks[i], QC_table)
            Cb_blocks[i] = quantization(Cb_blocks[i], QC_table)
        else:
            Y_blocks[i] = quantization(Y_blocks[i], O_table)
            Cr_blocks[i] = quantization(Cr_blocks[i], O_table)
            Cb_blocks[i] = quantization(Cb_blocks[i], O_table)

        Y_blocks[i] = zigzag(Y_blocks[i])
        Cr_blocks[i] = zigzag(Cr_blocks[i])
        Cb_blocks[i] = zigzag(Cb_blocks[i])

    # przygotowanie danych do kodowania RLE
    len_Y = len(Y_blocks)
    len_Y_block = len(Y_blocks[0])
    Y_temp = np.zeros((len_Y, len_Y_block, ))
    Cr_temp = np.zeros((len_Y, len_Y_block,))
    Cb_temp = np.zeros((len_Y, len_Y_block,))
    for i in range(len_Y):
        Y_temp[i, :] = Y_blocks[i]
        Cr_temp[i, :] = Cr_blocks[i]
        Cb_temp[i, :] = Cb_blocks[i]
    # kodowanie RLE
    Y_RLE_encoded = rle_encode(Y_temp)
    Cr_RLE_encoded = rle_encode(Cr_temp)
    Cb_RLE_encoded = rle_encode(Cb_temp)

    return Y_blocks, Cr_blocks, Cb_blocks, Y_RLE_encoded, Cr_RLE_encoded, Cb_RLE_encoded


def jpeg_decompression(Y_RLE_encoded, Cr_RLE_encoded, Cb_RLE_encoded, chroma_type, qt_mode, QY_table, QC_table, ones_table):
    # dekodowanie RLE
    Y_RLE_decoded = rle_decode(Y_RLE_encoded)
    Cr_RLE_decoded = rle_decode(Cr_RLE_encoded)
    Cb_RLE_decoded = rle_decode(Cb_RLE_encoded)
    # przygotowanie danych do dekompresji jpeg po dekodowaniu RLE
    Y2 = []
    Cr2 = []
    Cb2 = []
    len_Y = Y_RLE_decoded.shape[0]
    for i in range(len_Y):
        Y2.append(Y_RLE_decoded[i])
        Cr2.append(Cr_RLE_decoded[i])
        Cb2.append(Cb_RLE_decoded[i])

    # dekompresja jpeg
    for i in range(len(Y2)):
        Y2[i] = zigzag(Y2[i])
        Cr2[i] = zigzag(Cr2[i])
        Cb2[i] = zigzag(Cb2[i])

        if qt_mode:
            Y2[i] = dequantization(Y2[i], QY_table)
            Cr2[i] = dequantization(Cr2[i], QC_table)
            Cb2[i] = dequantization(Cb2[i], QC_table)
        else:
            Y2[i] = dequantization(Y2[i], ones_table)
            Cr2[i] = dequantization(Cr2[i], ones_table)
            Cb2[i] = dequantization(Cb2[i], ones_table)

        Y2[i] = idct2(Y2[i]) + 128
        Cr2[i] = idct2(Cr2[i]) + 128
        Cb2[i] = idct2(Cb2[i]) + 128

    # bloki do obrazka
    sizeA = 0
    sizeB = 0
    if chroma_type == "4:2:2":
        sizeA = int(np.sqrt(len(Y2)*2) * 8)
        sizeB = int(np.sqrt(len(Y2)*2) * 8/2)
    else:
        sizeA = int(np.sqrt(len(Y2)) * 8)
        sizeB = int(np.sqrt(len(Y2)) * 8)

    Y2 = blocks_8x8_ToData(Y2, sizeA, sizeB)
    Cr2 = blocks_8x8_ToData(Cr2, sizeA, sizeB)
    Cb2 = blocks_8x8_ToData(Cb2, sizeA, sizeB)

    if chroma_type != "4:4:4":
        Y2 = chromaResampling(Y2)
        Cr2 = chromaResampling(Cr2)
        Cb2 = chromaResampling(Cb2)

    # Przed konwersją warstwy Y na uint8, są na niej wartości z poza zakresu,
    # trzeba się ich pozbyć przy użyciu Y=np.clip(Y,0,255)
    Y2 = np.clip(Y2, 0, 255).astype(np.uint8)
    Cr2 = np.clip(Cr2, 0, 255).astype(np.uint8)
    Cb2 = np.clip(Cb2, 0, 255).astype(np.uint8)

    YCrCb2 = np.dstack([Y2, Cr2, Cb2]).astype(np.uint8)
    RGB = cv2.cvtColor(YCrCb2, cv2.COLOR_YCrCb2RGB).astype(int)

    return RGB, Y2, Cr2, Cb2



# img_256_256 = cv2.imread('0001.jpg')[700:700+256, 1900:1900+256]
# img_256_256 = cv2.imread('0002.jpg')[700:700+256, 1900:1900+256]
img_256_256 = cv2.imread('img_1.jpg')[700:700+256, 1900:1900+256]
img_256_256 = cv2.cvtColor(img_256_256, cv2.COLOR_BGR2RGB)
img_YCrCb = cv2.cvtColor(img_256_256, cv2.COLOR_RGB2YCrCb).astype(int)

Y_orig, Cr_orig, Cb_orig = np.clip(cv2.split(img_YCrCb), 0, 255)

fig, axs = plt.subplots(4, 2)
fig.set_size_inches(9, 13)
axs[0, 0].set_title("Original")
axs[0, 1].set_title("JPEG compression")

axs[0, 0].imshow(img_256_256)
axs[1, 0].imshow(Y_orig, cmap=plt.cm.gray)
axs[2, 0].imshow(Cr_orig, cmap=plt.cm.gray)
axs[3, 0].imshow(Cb_orig, cmap=plt.cm.gray)

Y, Cr, Cb, Y_RLE_enc, Cr_RLE_enc, Cb_RLE_enc = jpeg_compression(img_256_256, "4:2:2", False, QY, QC, O)
RGB_decom, Y_decom, Cr_decom, Cb_decom = jpeg_decompression(Y_RLE_enc, Cr_RLE_enc, Cb_RLE_enc, "4:2:2", False, QY, QC, O)

axs[0, 1].imshow(RGB_decom)
axs[1, 1].imshow(Y_decom, cmap=plt.cm.gray)
axs[2, 1].imshow(Cr_decom, cmap=plt.cm.gray)
axs[3, 1].imshow(Cb_decom, cmap=plt.cm.gray)

plt.savefig('jpeg_images.jpg')
plt.show()

Y_size_before = get_size(Y_orig.tolist())
Y_size_after = get_size(Y_RLE_enc)
Cr_size_before = get_size(Cr_orig.tolist())
Cr_size_after = get_size(Cr_RLE_enc)
Cb_size_before = get_size(Cb_orig.tolist())
Cb_size_after = get_size(Cb_RLE_enc)
print(f"\t\t\tAnaliza 3 - 0003.jpg\n"
    f"Warstwa Y:\n"
    f"Rozmiar (przed): {Y_size_before} bytes, {get_human_size(Y_size_before)}\n"
    f"Rozmiar    (po): {Y_size_after} bytes, {get_human_size(Y_size_after)}\n"
    f"Warstwa Cr:\n"
    f"Rozmiar (przed): {Cr_size_before} bytes, {get_human_size(Cr_size_before)}\n"
    f"Rozmiar    (po): {Cr_size_after} bytes, {get_human_size(Cr_size_after)}\n"
    f"Warstwa Cb:\n"
    f"Rozmiar (przed): {Cb_size_before} bytes, {get_human_size(Cb_size_before)}\n"
    f"Rozmiar    (po): {Cb_size_after} bytes, {get_human_size(Cb_size_after)}")
