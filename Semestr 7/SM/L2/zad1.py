import numpy as np
import matplotlib.pyplot as plt
import cv2

def imgToUInt8(img):
  if np.issubdtype(img.dtype, np.unsignedinteger):
    return img

  img = img*255.0
  img = img.astype('uint8')

  return img

def imgToFloat(img):
  if np.issubdtype(img.dtype, np.floating):
    return img

  img = img/255.0

  return img


if __name__ == '__main__':
  img1 = plt.imread('A1.png')
  img2 = cv2.imread('A1.png')

  print(img1.dtype)
  print(img1.shape)
  print(np.min(img1),np.max(img1))

  print(img2.dtype)
  print(img2.shape)
  print(np.min(img2),np.max(img2))

  img1 = imgToUInt8(img1)
  img2 = imgToFloat(img2)

  print(img1.dtype)
  print(img2.dtype)




