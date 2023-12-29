import numpy as np
import matplotlib.pyplot as plt
import cv2
import scipy.fftpack

def rle_encode(img):
  img = img.astype(int)
  img_shape = img.shape
  img_flatten = img.flatten()
  sign_counter = 0
  previous_sign = None
  coded_stream = []
  for sign in img_flatten:
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

  return [img_shape, coded_stream]

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

def CompressBlock(block, Q):
  # Ensure Q has the same shape as block
  Q = Q[:block.shape[0], :block.shape[1]]

  # Apply the 2D DCT to the block
  dct_block = dct2(block)

  # Quantize the DCT coefficients
  quantized_block = np.round(dct_block / Q)

  # Flatten the quantized block into a 1D vector
  vector = zigzag(quantized_block)

  return vector

def DecompressBlock(vector, Q):
  # Reshape the vector back into a 2D block
  block_shape = (8, 8)
  quantized_block = zigzag(vector).reshape(block_shape)

  # Dequantize the DCT coefficients
  dequantized_block = quantized_block * Q

  # Apply the 2D inverse DCT to the block
  block = idct2(dequantized_block)

  return block

## podział na bloki
# L - warstwa kompresowana
# S - wektor wyjściowy
def CompressLayer(L,Q):
  S=np.array([])
  for w in range(0,L.shape[0],8):
    for k in range(0,L.shape[1],8):
      block=L[w:(w+8),k:(k+8)]
      S=np.append(S, CompressBlock(block,Q))

  return S

## wyodrębnianie bloków z wektora
# L - warstwa o oczekiwanym rozmiarze
# S - długi wektor zawierający skompresowane dane
def DecompressLayer(S,Q):
  # Calculate the dimensions of the original image
  num_blocks = S.shape[0] // 64
  height = int(np.sqrt(num_blocks)) * 8
  width = int(np.sqrt(num_blocks)) * 8

  # Initialize L as a 2D array of zeros
  L = np.zeros((height, width))

  for idx,i in enumerate(range(0,S.shape[0],64)):
    vector=S[i:(i+64)]
    m=L.shape[0]/8
    k=int((idx%m)*8)
    w=int((idx//m)*8)
    L[w:(w+8),k:(k+8)]=DecompressBlock(vector,Q)

  return L

def dct2(a):
    return scipy.fftpack.dct( scipy.fftpack.dct( a.astype(float), axis=0, norm='ortho' ), axis=1, norm='ortho' )

def idct2(a):
    return scipy.fftpack.idct( scipy.fftpack.idct( a.astype(float), axis=0 , norm='ortho'), axis=1 , norm='ortho')

QY= np.array([
        [16, 11, 10, 16, 24,  40,  51,  61],
        [12, 12, 14, 19, 26,  58,  60,  55],
        [14, 13, 16, 24, 40,  57,  69,  56],
        [14, 17, 22, 29, 51,  87,  80,  62],
        [18, 22, 37, 56, 68,  109, 103, 77],
        [24, 36, 55, 64, 81,  104, 113, 92],
        [49, 64, 78, 87, 103, 121, 120, 101],
        [72, 92, 95, 98, 112, 100, 103, 99],
        ])

QC= np.array([
        [17, 18, 24, 47, 99, 99, 99, 99],
        [18, 21, 26, 66, 99, 99, 99, 99],
        [24, 26, 56, 99, 99, 99, 99, 99],
        [47, 66, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        [99, 99, 99, 99, 99, 99, 99, 99],
        ])

QN= np.ones((8,8))

def zigzag(A):
    template= np.array([
            [0,  1,  5,  6,  14, 15, 27, 28],
            [2,  4,  7,  13, 16, 26, 29, 42],
            [3,  8,  12, 17, 25, 30, 41, 43],
            [9,  11, 18, 24, 31, 40, 44, 53],
            [10, 19, 23, 32, 39, 45, 52, 54],
            [20, 22, 33, 38, 46, 51, 55, 60],
            [21, 34, 37, 47, 50, 56, 59, 61],
            [35, 36, 48, 49, 57, 58, 62, 63],
            ])
    if len(A.shape)==1:
      B=np.zeros((8,8))
      for r in range(0,8):
        for c in range(0,8):
          if c < A.shape[1]:  # Ensure c is within bounds
            B[r,c]=A[template[r,c]]
    else:
      B=np.zeros((64,))
      for r in range(0,8):
        for c in range(0,8):
          if c < A.shape[1]:  # Ensure c is within bounds
            B[template[r,c]]=A[r,c]

    return B

class dataContainer:
  Y = np.array([])
  Cb = np.array([])
  Cr = np.array([])
  ChromaRatio = "4:4:4"
  QY = np.ones((8,8))
  QC = np.ones((8,8))
  shape = (0,0,3)

def CompressJPEG(RGB, Ratio="4:4:4", QY=np.ones((8,8)), QC=np.ones((8,8))):
  # RGB -> YCrCb
  img_YCrCb = cv2.cvtColor(RGB, cv2.COLOR_BGR2YCrCb)

  # Split into Y, Cr, Cb channels
  Y, Cr, Cb = cv2.split(img_YCrCb)

  # Chroma subsampling
  if Ratio == "4:2:2":
    Cr = cv2.resize(Cr, (Cr.shape[1] // 2, Cr.shape[0]))
    Cb = cv2.resize(Cb, (Cb.shape[1] // 2, Cb.shape[0]))
  elif Ratio == "4:2:0":
    Cr = cv2.resize(Cr, (Cr.shape[1] // 2, Cr.shape[0] // 2))
    Cb = cv2.resize(Cb, (Cb.shape[1] // 2, Cb.shape[0] // 2))

  # Initialize compressed channels
  Y_compressed = np.array([])
  Cr_compressed = np.array([])
  Cb_compressed = np.array([])

  # Process blocks of 8x8
  for i in range(0, Y.shape[0], 8):
    for j in range(0, Y.shape[1], 8):
      # DCT, quantization, zigzaging
      Y_compressed = np.append(Y_compressed, CompressBlock(Y[i:i+8, j:j+8], QY))
      if i < Cr.shape[0] and j < Cr.shape[1]:
        Cr_compressed = np.append(Cr_compressed, CompressBlock(Cr[i:i+8, j:j+8], QC))
        Cb_compressed = np.append(Cb_compressed, CompressBlock(Cb[i:i+8, j:j+8], QC))

  # RLC compression
  Y_compressed = rle_encode(Y_compressed)
  Cr_compressed = rle_encode(Cr_compressed)
  Cb_compressed = rle_encode(Cb_compressed)

  # Create JPEG object
  JPEG = dataContainer()
  JPEG.Ratio = Ratio
  JPEG.QY = QY
  JPEG.QC = QC
  JPEG.Y = Y_compressed
  JPEG.Cr = Cr_compressed
  JPEG.Cb = Cb_compressed

  return JPEG

def DecompressJPEG(JPEG):
    # RLC decompression
    Y_decompressed = rle_decode(JPEG.Y)
    Cr_decompressed = rle_decode(JPEG.Cr)
    Cb_decompressed = rle_decode(JPEG.Cb)

    # Initialize decompressed channels
    Y = np.zeros((JPEG.Y.shape[0], JPEG.Y.shape[1]))
    Cr = np.zeros((JPEG.Cr.shape[0], JPEG.Cr.shape[1]))
    Cb = np.zeros((JPEG.Cb.shape[0], JPEG.Cb.shape[1]))

    # Process blocks of 8x8
    for i in range(0, Y_decompressed.shape[0], 64):
        # Dezigzagging, dequantization, IDCT
        Y[i:i+64] = DecompressBlock(Y_decompressed[i:i+64], JPEG.QY)
        if i < Cr_decompressed.shape[0]:
            Cr[i:i+64] = DecompressBlock(Cr_decompressed[i:i+64], JPEG.QC)
            Cb[i:i+64] = DecompressBlock(Cb_decompressed[i:i+64], JPEG.QC)

    # Chroma resampling
    if JPEG.Ratio == "4:2:2":
        Cr = cv2.resize(Cr, (Y.shape[1], Y.shape[0]))
        Cb = cv2.resize(Cb, (Y.shape[1], Y.shape[0]))
    elif JPEG.Ratio == "4:2:0":
        Cr = cv2.resize(Cr, (Y.shape[1], Y.shape[0]))
        Cb = cv2.resize(Cb, (Y.shape[1], Y.shape[0]))

    # Merge Y, Cr, Cb channels
    img_YCrCb = cv2.merge([Y, Cr, Cb])

    # YCrCb -> RGB
    RGB = cv2.cvtColor(img_YCrCb, cv2.COLOR_YCrCb2BGR)

    return RGB

if __name__ == "__main__":
  # Read the image
  img = cv2.imread('img_1.jpg')

  # Define the quantization matrices
  QY = np.ones((8,8))
  QC = np.ones((8,8))

  # Compress the image
  JPEG = CompressJPEG(img, Ratio="4:4:4", QY=QY, QC=QC)

  # Decompress the image
  img_decompressed = DecompressJPEG(JPEG)

  # Display the original and decompressed images
  cv2.imshow('Original', img)
  cv2.imshow('Decompressed', img_decompressed)
  cv2.waitKey(0)
  cv2.destroyAllWindows()


