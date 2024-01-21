import cv2
import numpy as np
import matplotlib.pyplot as plt

##############################################################################
######   Konfiguracja       ##################################################
##############################################################################

kat = '.\\'                               # katalog z plikami wideo
plik = "clip_1.mp4"                       # nazwa pliku
ile = 35                                 # ile klatek odtworzyć? <0 - całość
key_frame_counter = 4                     # co która klatka ma być kluczowa i nie podlegać kompresji
plot_frames = np.array([31])           # automatycznie wyrysuj wykresy
auto_pause_frames = np.array([])        # automatycznie za pauzuj dla klatki
#subsampling = "4:2:0"                     # parametry dla chroma subsampling
#dzielnik = 1                              # dzielnik przy zapisie różnicy
wyswietlaj_kaltki = True                  # czy program ma wyświetlać klatki
ROI = [[450,750,600,900]]                   # wyświetlane fragmenty (można podać kilka)

##############################################################################
####     Kompresja i dekompresja    ##########################################
##############################################################################
class data:
  def init(self):
    self.Y = None
    self.Cb = None
    self.Cr = None

def Chroma_subsampling(L, subsampling):
  if subsampling == '4:4:4':
    return L
  elif subsampling == '4:2:2':
    return L[:, ::2]
  elif subsampling == '4:4:0':
    return L[::2, :]
  elif subsampling == '4:2:0':
    return L[::2, ::2]
  elif subsampling == '4:1:1':
    return L[:, ::4]
  elif subsampling == '4:1:0':
    return L[::2, ::4]

def Chroma_resampling(L, subsampling):
  if subsampling == '4:4:4':
    return L
  elif subsampling == '4:2:2':
    return np.repeat(L, 2, axis=1)
  elif subsampling == '4:4:0':
    return np.repeat(L, 2, axis=0)
  elif subsampling == '4:2:0':
    return np.repeat(np.repeat(L, 2, axis=0), 2, axis=1)
  elif subsampling == '4:1:1':
    return np.repeat(L, 4, axis=1)
  elif subsampling == '4:1:0':
    return np.repeat(L, 2, axis=0).repeat(4, axis=1)

def frame_image_to_class(frame,subsampling):
  Frame_class = data()
  Frame_class.Y = frame[:,:,0].astype(int)
  Frame_class.Cb = Chroma_subsampling(frame[:,:,2].astype(int), subsampling)
  Frame_class.Cr = Chroma_subsampling(frame[:,:,1].astype(int), subsampling)
  return Frame_class

def frame_layers_to_image(Y,Cr,Cb,subsampling):
  Cb = Chroma_resampling(Cb,subsampling)
  Cr = Chroma_resampling(Cr,subsampling)
  return np.dstack([Y, Cr, Cb]).clip(0, 255).astype(np.uint8)

# RLE ###################################################################
''' NIE ZAIMPLEMENTOWANE
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

def rle_decode(img_shape, coded_stream):
  decoded_stream = []
  for i in range(0, len(coded_stream), 2):
    sign = coded_stream[i + 1]
    sign_counter = coded_stream[i]
    for j in range(sign_counter):
      decoded_stream.append(sign)
  decoded_stream = np.array(decoded_stream)
  decoded_stream = decoded_stream.reshape(img_shape)

  return decoded_stream

def compress_KeyFrame(Frame_class):
  KeyFrame = data()
  KeyFrame.Y = rle_encode(Frame_class.Y)
  KeyFrame.Cb = rle_encode(Frame_class.Cb)
  KeyFrame.Cr = rle_encode(Frame_class.Cr)
  return KeyFrame

def decompress_KeyFrame(KeyFrame, subsampling):
  Y = rle_decode(*KeyFrame.Y)
  Cb = rle_decode(*KeyFrame.Cb)
  Cr = rle_decode(*KeyFrame.Cr)
  frame_image = frame_layers_to_image(Y, Cr, Cb, subsampling)
  return frame_image

def compress_not_KeyFrame(Frame_class, KeyFrame, dzielnik):
  Compress_data = data()
  Compress_data.Y = rle_encode((Frame_class.Y - KeyFrame.Y) / dzielnik)
  Compress_data.Cb = rle_encode((Frame_class.Cb - KeyFrame.Cb) / dzielnik)
  Compress_data.Cr = rle_encode((Frame_class.Cr - KeyFrame.Cr) / dzielnik)
  return Compress_data

def decompress_not_KeyFrame(Compress_data, KeyFrame, dzielnik, subsampling):
  Y = rle_decode(*Compress_data.Y) * dzielnik + KeyFrame.Y
  Cb = rle_decode(*Compress_data.Cb) * dzielnik + KeyFrame.Cb
  Cr = rle_decode(*Compress_data.Cr) * dzielnik + KeyFrame.Cr
  return frame_layers_to_image(Y, Cr, Cb, subsampling)
'''
#########################################################################

# BEZ RLE ###############################################################
def compress_KeyFrame(Frame_class):
  KeyFrame = data()
  KeyFrame.Y = Frame_class.Y
  KeyFrame.Cb = Frame_class.Cb
  KeyFrame.Cr = Frame_class.Cr
  return KeyFrame

def decompress_KeyFrame(KeyFrame, subsampling):
  Y = KeyFrame.Y
  Cb = KeyFrame.Cb
  Cr = KeyFrame.Cr
  frame_image=frame_layers_to_image(Y,Cr,Cb,subsampling)
  return frame_image

def compress_not_KeyFrame(Frame_class, KeyFrame, dzielnik):
  Compress_data = data()
  Compress_data.Y = (Frame_class.Y - KeyFrame.Y) / dzielnik
  Compress_data.Cb = (Frame_class.Cb - KeyFrame.Cb) / dzielnik
  Compress_data.Cr = (Frame_class.Cr - KeyFrame.Cr) / dzielnik
  return Compress_data

def decompress_not_KeyFrame(Compress_data, KeyFrame, dzielnik, subsampling):
  Y = Compress_data.Y * dzielnik + KeyFrame.Y
  Cb = Compress_data.Cb * dzielnik + KeyFrame.Cb
  Cr = Compress_data.Cr * dzielnik + KeyFrame.Cr
  return frame_layers_to_image(Y, Cr, Cb, subsampling)

#########################################################################

def plotDiffrence(ReferenceFrame , DecompressedFrame, ROI, ss, dz, plot_frame):
  # Convert frames from YCrCb to RGB
  ReferenceFrameRGB = cv2.cvtColor(ReferenceFrame, cv2.COLOR_YCrCb2RGB)
  DecompressedFrameRBG = cv2.cvtColor(DecompressedFrame, cv2.COLOR_YCrCb2RGB)

  fig, axs = plt.subplots(4, 3, sharey=True, figsize=(8,12))
  fig.suptitle("File:{}, Subsampling={}, Divider={}, KeyFrameCounter={}, Frame={}".format(plik, ss, dz, key_frame_counter, plot_frame[0]))
  fig.tight_layout(pad=1.0)
  axs[0, 0].set_title('Reference Frame')
  axs[0, 1].set_title('Difference')
  axs[0, 2].set_title('Decompressed Frame')

  axs[0, 0].imshow(ReferenceFrameRGB[ROI[0]:ROI[1], ROI[2]:ROI[3]])
  axs[0, 2].imshow(DecompressedFrameRBG[ROI[0]:ROI[1], ROI[2]:ROI[3]])
  diff = ReferenceFrameRGB[ROI[0]:ROI[1], ROI[2]:ROI[3]].astype(float) - DecompressedFrameRBG[ROI[0]:ROI[1], ROI[2]:ROI[3]].astype(float)
  print("RGB: min diff =", np.min(diff), "max diff =", np.max(diff))
  axs[0, 1].imshow(diff, vmin=np.min(diff), vmax=np.max(diff), cmap=plt.cm.gray)
  axs[0, 1].set_xlabel("RGB: min diff = {}, max diff = {}".format(np.min(diff), np.max(diff)))

  axs[1, 0].imshow(ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 0], cmap=plt.cm.gray)
  axs[1, 2].imshow(DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 0], cmap=plt.cm.gray)
  diff = ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 0].astype(float) - DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 0].astype(float)
  #print("Y: min diff =", np.min(diff), "max diff =", np.max(diff))
  axs[1, 1].imshow(diff, vmin=np.min(diff), vmax=np.max(diff), cmap=plt.cm.gray)
  axs[1, 1].set_xlabel("Y: min diff = {},  max diff = {}".format(np.min(diff), np.max(diff)))

  axs[2, 0].imshow(ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 1], cmap=plt.cm.gray)
  axs[2, 2].imshow(DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 1], cmap=plt.cm.gray)
  diff = ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 1].astype(float) - DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 1].astype(float)
  #print("Cr: min diff =", np.min(diff), "max diff =", np.max(diff))
  axs[2, 1].imshow(diff, vmin=np.min(diff), vmax=np.max(diff), cmap=plt.cm.gray)
  axs[2, 1].set_xlabel("Cr: min diff = {},  max diff = {}".format(np.min(diff), np.max(diff)))

  axs[3, 0].imshow(ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 2], cmap=plt.cm.gray)
  axs[3, 2].imshow(DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 2], cmap=plt.cm.gray)
  diff = ReferenceFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 2].astype(float) - DecompressedFrame[ROI[0]:ROI[1], ROI[2]:ROI[3], 2].astype(float)
  #print("Cb: min diff =", np.min(diff), "max diff =", np.max(diff))
  axs[3, 1].imshow(diff, vmin=np.min(diff), vmax=np.max(diff), cmap=plt.cm.gray)
  axs[3, 1].set_xlabel("Cb: min diff = {},  max diff = {}".format(np.min(diff), np.max(diff)))

  #plt.show()
  plt.savefig("bezrle_comp_file_{}_subsampling_{}_divider_{}_frame_{}.png".format(plik[:-4], ss.replace(":", "", 2), dz, plot_frame[0]))

##############################################################################
####     Głowna pętla programu      ##########################################
##############################################################################
variations = ["4:4:4", "4:2:2", "4:4:0", "4:2:0", "4:1:1", "4:1:0", 1, 2, 4, 8]

for i in range(len(variations)):
  if i < 6:
    ss = variations[i]
    div = variations[6]
  else:
    ss = variations[0]
    div = variations[i]

  cap = cv2.VideoCapture(kat + '\\' + plik)

  if ile < 0:
    ile = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

  cv2.namedWindow('Normal Frame')
  cv2.namedWindow('Decompressed Frame')

  compression_information = np.zeros((3, ile))

  for i in range(ile):
    ret, frame = cap.read()
    if wyswietlaj_kaltki:
      cv2.imshow('Normal Frame', frame)
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2YCrCb)
    Frame_class = frame_image_to_class(frame, ss)
    if (i % key_frame_counter) == 0: # pobieranie klatek kluczowych
      KeyFrame = compress_KeyFrame(Frame_class)
      cY = KeyFrame.Y
      cCb = KeyFrame.Cb
      cCr = KeyFrame.Cr
      Decompresed_Frame = decompress_KeyFrame(KeyFrame, ss)
    else: # kompresja
      Compress_data = compress_not_KeyFrame(Frame_class, KeyFrame, div)
      cY = Compress_data.Y
      cCb = Compress_data.Cb
      cCr = Compress_data.Cr
      Decompresed_Frame = decompress_not_KeyFrame(Compress_data,  KeyFrame, div, ss)

    compression_information[0,i] = (frame[:,:,0].size - len(cY)) / frame[:,:,0].size
    compression_information[1,i] = (frame[:,:,0].size - len(cCb)) / frame[:,:,0].size
    compression_information[2,i] = (frame[:,:,0].size - len(cCr)) / frame[:,:,0].size
    if wyswietlaj_kaltki:
      cv2.imshow('Decompressed Frame',cv2.cvtColor(Decompresed_Frame, cv2.COLOR_YCrCb2BGR))

    if np.any(plot_frames == i): # rysuj wykresy
      for r in ROI:
        plotDiffrence(frame, Decompresed_Frame, r, ss, div, plot_frames)

    if np.any(auto_pause_frames == i):
      cv2.waitKey(-1) #wait until any key is pressed

    k = cv2.waitKey(1) & 0xff

    if k == ord('q'):
      break
    elif k == ord('p'):
      cv2.waitKey(-1) #wait until any key is pressed

  plt.figure()
  plt.plot(np.arange(0,ile),compression_information[0,:] * 100)
  plt.plot(np.arange(0,ile),compression_information[1,:] * 100)
  plt.plot(np.arange(0,ile),compression_information[2,:] * 100)
  plt.legend(["Y","Cb","Cr"])
  plt.title("File:{}, subsampling={}, divider={}, KeyFrame={} ".format(plik[:-4], ss, div, key_frame_counter))
  plt.savefig("bezrle_plot_file_{}_subsampling_{}_divider_{}_keyframe_{}.png".format(plik[:-4], ss.replace(":", "", 2), div, key_frame_counter))