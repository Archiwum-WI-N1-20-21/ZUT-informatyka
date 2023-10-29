import matplotlib.pyplot as plt
import numpy as np
import soundfile as sf
import scipy.fftpack

def plotAudio(Signal,Fs,TimeMargin=[0,0.02]):
  plt.figure()
  plt.subplot(2,1,1)
  plt.plot(np.arange(0,data.shape[0])/fs,data)
  plt.xlim(TimeMargin[0], TimeMargin[1])
  plt.title("Sygnał dźwiękowy")
  plt.xlabel("Czas (s)")
  plt.subplot(2,1,2)
  yf = scipy.fftpack.fft(data,fsize)
  plt.plot(np.arange(0,fs/2,fs/fsize),20*np.log10( np.abs(yf[:fsize//2])))
  plt.title("Widmo")
  plt.xlabel("Częstotliwość (Hz)")
  plt.ylabel("Natężenie (dB)")
  plt.show()

if __name__ == '__main__':
  fsize=2**8

  data, fs = sf.read('sin_440Hz.wav', dtype=np.int32)

  plotAudio(data, fs)