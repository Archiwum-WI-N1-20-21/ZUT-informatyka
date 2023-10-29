import numpy as np
import scipy.fftpack
import soundfile as sf

if __name__ == '__main__':
  data, fs = sf.read('sound1.wav', dtype=np.int32)

  left_channel = data[:, 0]
  right_channel = data[:, 1]
  mix = (data[:, 0] + data[:, 1]) / 2

  sf.write('left.wav', left_channel, fs)
  sf.write('right.wav', right_channel, fs)
  sf.write('mix.wav', mix, fs)