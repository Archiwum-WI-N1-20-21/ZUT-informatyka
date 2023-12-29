import numpy as np
import matplotlib.pyplot as plt
import sys

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
  if isinstance(obj,np.ndarray):
    size = obj.nbytes
  elif isinstance(obj, dict):
    size += sum([get_size(v, seen) for v in obj.values()])
    size += sum([get_size(k, seen) for k in obj.keys()])
  elif hasattr(obj, '__dict__'):
    size += get_size(obj.__dict__, seen)
  elif hasattr(obj, '__iter__') and not isinstance(obj, (str, bytes, bytearray)):
    size += sum([get_size(i, seen) for i in obj])
  return size

def compression_rate(size_before, size_after):
    return round(size_before / size_after, 4)

def compression_ratio(size_before, size_after):
    return round((size_after / size_before) * 100, 2)

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

def byte_run_encode(img):
  img = img.astype(int)
  img_shape = img.shape
  img_flatten = img.flatten()
  pixel_counter = 0
  previous_pixel = None
  encoded_stream = []
  for pixel in img_flatten:
    if pixel == previous_pixel:
        pixel_counter += 1
    else:
        if previous_pixel is not None:
            encoded_stream.append(pixel_counter)
            encoded_stream.append(previous_pixel)
        pixel_counter = 1
        previous_pixel = pixel
  encoded_stream.append(pixel_counter)
  encoded_stream.append(previous_pixel)
  encoded_stream = np.array(encoded_stream)

  return [img_shape, encoded_stream]

# DOESN'T WORK
def byte_run_decode(coded_data):
  decoded_stream = []
  for i in range(0, len(coded_data), 2):
      count = coded_data[1][i]
      pixel = coded_data[1][i+1]
      decoded_stream.extend([pixel]*count)
  decoded_stream = np.array(decoded_stream).reshape(coded_data[0])

  return decoded_stream

def tests():
  test_data = [np.array([1,1,1,1,2,1,1,1,1,2,1,1,1,1]),
  np.array([1,2,3,1,2,3,1,2,3]),
  np.array([5,1,5,1,5,5,1,1,5,5,1,1,5]),
  np.array([-1,-1,-1,-5,-5,-3,-4,-2,1,2,2,1]),
  np.zeros((1,520)),
  np.arange(0,521,1),
  np.eye(7),
  np.dstack([np.eye(7),np.eye(7),np.eye(7)]),
  np.ones((1,1,1,1,1,1,10))]

  for i in range(2):
    for j in range(len(test_data)):
      if i == 0:
        print('Test {} for algorithm {}'.format(j, 'RLE'))
        test_encode = rle_encode(test_data[j])
        test_decode = rle_decode(test_encode)
        if np.allclose(test_data[j], test_decode): print("Passed\n")
        else: print("Failed\n")
      if i == 1:
        continue
        print('Test {} for algorithm {}'.format(j, 'Byte-run'))
        test_encode = byte_run_encode(test_data[j])
        test_decode = byte_run_decode(test_encode)
        if np.allclose(test_data[j], test_decode): print("Passed\n")
        else: print("Failed\n")

if __name__ == '__main__':
  images = ['rys_techniczny.png', 'rys_dokument.png', 'rys_kolorowy.png']
  algorithm = ['RLE', 'Byte-run']

  tests()

  for i in range(2):
    for j in range(3):
      img = plt.imread(images[j])

      if i == 0:
        img_encoded = rle_encode(img)
        img_decoded = rle_decode(img_encoded)
      if i == 1:
        continue
        img_encoded = byte_run_encode(img)
        img_decoded = byte_run_decode(img_encoded)

      print('Image: {}'.format(images[j]))
      print('Algorithm: {}'.format(algorithm[i]))
      print('Shape before: {}'.format(img.shape))
      print('Shape after: {}'.format(img_decoded.shape))
      print('Size before: {}'.format(get_size(img)))
      print('Size after: {}'.format(get_size(img_encoded)))
      print('Compression rate: {}, compression ratio {}%'.format(compression_rate(get_size(img), get_size(img_encoded)), compression_ratio(get_size(img), get_size(img_encoded))))
      print()