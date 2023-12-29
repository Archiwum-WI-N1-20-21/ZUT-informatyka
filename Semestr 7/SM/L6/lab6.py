import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
import soundfile as sf

def kwant(data, bit):
  d = 2 ** bit - 1

  if np.issubdtype(data.dtype, np.floating):
      n = 1
      m = -1
  else:
      n = np.iinfo(data.dtype).max
      m = np.iinfo(data.dtype).min

  data_out = data.astype(float)
  data_out = (data_out - m) / (n - m) * d
  data_out = np.round(data_out)
  data_out = data_out / d * (n - m) + m

  return data_out.astype(data.dtype)

def alaw(data):
  A = 87.6
  y = np.zeros(data.shape)
  idx = np.abs(data) < (1 / A)
  y[idx] = np.sign(data[idx]) * ((A * np.abs(data[idx])) / (1 + np.log(A)))
  y[np.logical_not(idx)] = np.sign(data[np.logical_not(idx)]) * ((1 + np.log(A*np.abs(data[np.logical_not(idx)]))) / (1 + np.log(A)))

  return y

def decodeAlaw(data):
  A = 87.6
  y = np.zeros(data.shape)
  idx = np.abs(data) < 1 / (1 + np.log(A))
  y[idx] = np.sign(data[idx]) * ((np.abs(data[idx]) * (1+np.log(A))) / (A))
  y[np.logical_not(idx)] = np.sign(data[np.logical_not(idx)]) * ((np.exp(np.abs(data[np.logical_not(idx)]) * ((1 + np.log(A)))-1))/(A))

  return y

def ulaw(data):
  u = 255
  y = np.zeros(data.shape)
  y = np.sign(data) * ((np.log(1 + u * np.abs(data))) / (np.log(1 + u)))

  return y

def decodeUlaw(data):
  u = 255
  y = np.zeros(data.shape)
  y = np.sign(data) * (1 / u) * ((1 + u) ** np.abs(data) - 1)

  return y

def dpcmNoPredict(data, bit):
  y = np.zeros(data.shape)
  e = 0
  for i in range(0, data.shape[0]):
    y[i] = kwant(data[i] - e, bit)
    e += y[i]

  return y

def dpcmNoPredictDecode(data):
  y = np.zeros(data.shape)
  e = 0
  for i in range(0, data.shape[0]):
    y[i] = data[i] + e
    e = y[i]

  return y

def dpcmPredict(data, bit, n):
  y = np.zeros(data.shape)
  xp = np.zeros(data.shape)
  e = 0
  for i in range(1, data.shape[0]):
    y[i] = kwant(data[i] - e, bit)
    xp[i] = y[i] + e
    idx = np.arange(max(0, i - n), i)
    e = np.mean(xp[idx])

  return y

def dpcmPredictDecode(data, n):
  y = np.zeros(data.shape)
  xp = np.zeros(data.shape)
  e = 0
  for i in range(1, y.shape[0]):
    y[i] = data[i] + e
    xp[i] = y[i]
    idx = np.arange(max(0, i - n), i)
    e = np.mean(xp[idx])

  return y

def lawComarsionGraph(data, i):
  plt.suptitle('A-law vs. mu-law')
  plt.subplot(1, 2, 1)
  x = data
  y = alaw(x)
  plt.plot(x, y, label='Sygnał po kompresji a-law')

  y = kwant(y, 8)
  plt.plot(x, y, label='Sygnał po kompresji a-law, kwantyzcja 8 bitów')

  y = ulaw(x)
  plt.plot(x, y, label='Sygnał po kompresji mu-law')

  y = kwant(y, 8)
  plt.plot(x, y, label='Sygnał po kompresji mu-law, kwantyzcja 8 bitów')

  plt.legend(loc=2)
  plt.title('Krzywa kompresji')
  if i == 1:
    plt.xlim(-0.9, -0.8)
    plt.ylim(-0.985, -0.960)
  elif i == 2:
    plt.xlim(-0.01, 0.01)
    plt.ylim(-0.15, 0.15)

  plt.subplot(1, 2, 2)
  plt.plot(x, x, label='Sygnał oryginalny')

  y = alaw(x)
  y = kwant(y, 8)
  y = decodeAlaw(y)
  plt.plot(x, y, label='Sygnał po dekompresji z A-law, Kwantyzacja 8 bitów')

  y = ulaw(x)
  y = kwant(y, 8)
  y = decodeUlaw(y)
  plt.plot(x, y, label='Sygnał po dekompresji z mu-law, Kwantyzacja 8 bitów')

  y = kwant(x, 8)
  plt.plot(x, y, label='Sygnał oryginalny, Kwantyzacja 8 bitów')

  plt.legend(loc=2)
  plt.title('Krzywa po dekompresji')
  if i == 1:
    plt.xlim(-0.9, -0.8)
    plt.ylim(-0.92, -0.8)
  elif i == 2:
    plt.xlim(-0.01, 0.01)
    plt.ylim(-0.01, 0.01)

  plt.show()

def dpcmLawSubplotComparsionGraph(x, y, i):
  plt.suptitle('y = 0.9 * sin(pi * x * 4), kwantyzacja 6 bitów')
  plt.subplots_adjust(hspace=0.5)
  plt.subplot(5, 1, 1)
  plt.title("Sygnał oryginalny")
  plt.plot(x, y)
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.subplot(5, 1, 2)
  plt.title("Kompresja A-law")
  yy = alaw(y)
  yy = kwant(yy, 6)
  yy = decodeAlaw(yy)
  plt.plot(x, yy)
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.subplot(5, 1, 3)
  plt.title("Kompresja Mu-law")
  yy = ulaw(y)
  yy = kwant(yy, 6)
  yy = decodeUlaw(yy)
  plt.plot(x, yy)
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.subplot(5, 1, 5)
  plt.title("Kompresja DPCM bez predykcji")
  yy = dpcmNoPredict(y, 6)
  yy = dpcmNoPredictDecode(yy)
  plt.plot(x, yy)
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.subplot(5, 1, 4)
  plt.title("Kompresja DPCM z predykcją")
  yy = dpcmPredict(y, 6, 4)
  yy = dpcmPredictDecode(yy, 4)
  plt.plot(x, yy)
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.show()

def dpcmLawStackedComparsionGraph(x, y, i):
  if i == 0:
    plt.suptitle('y = 0.9 * sin(pi * x * 4), kwantyzacja 6 bitów, przykład A')
  else:
    plt.suptitle('y = 0.9 * sin(pi * x * 4), kwantyzacja 6 bitów, przykład B')
  plt.plot(x, y, label='Sygnał oryginalny')
  if i == 1:
    plt.xlim(-0.5, -0.25)

  yy = alaw(y)
  yy = kwant(yy, 6)
  yy = decodeAlaw(yy)
  plt.plot(x, yy, label='Sygnał po dekompresji A-law')
  if i == 1:
    plt.xlim(-0.5, -0.25)

  yy = ulaw(y)
  yy = kwant(yy, 6)
  yy = decodeUlaw(yy)
  plt.plot(x, yy, label='Sygnał po dekompresji Mu-law')
  if i == 1:
    plt.xlim(-0.5, -0.25)

  yy = dpcmNoPredict(y, 6)
  yy = dpcmNoPredictDecode(yy)
  plt.plot(x, yy, label='Sygnał po dekompresji DPCM bez predykcji')
  if i == 1:
    plt.xlim(-0.5, -0.25)

  yy = dpcmPredict(y, 6, 4)
  yy = dpcmPredictDecode(yy, 4)
  plt.plot(x, yy, label='Sygnał po dekompresji DPCM z predykcją')
  if i == 1:
    plt.xlim(-0.5, -0.25)

  plt.legend(loc=2)

  plt.show()


def lawGraphs():
  x = np.linspace(-1 ,1 ,1000)

  for i in range(0, 3):
    lawComarsionGraph(x, i)

def dpcmLawGraphs():
  x = np.linspace(-1 ,1 ,1000)
  y = 0.9 * np.sin(np.pi * x * 4)

  for i in range(0, 2):
    dpcmLawSubplotComparsionGraph(x, y, i)

  for i in range(0, 2):
    dpcmLawStackedComparsionGraph(x, y, i)

def soundTest8bits(files):
  for file in files:
    sound, fs = sf.read(file)

    print("File: " + file)
    sd.play(sound, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

    print("A-law")
    y = alaw(sound)
    y = kwant(y, 8)
    y = decodeAlaw(y)
    sd.play(y, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

    print("Mu-law")
    y = ulaw(sound)
    y = kwant(y, 8)
    y = decodeUlaw(y)
    sd.play(y, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

    print("DPCM")
    y = dpcmNoPredict(sound, 8)
    y = dpcmNoPredictDecode(y)
    sd.play(y, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

    print("DPCM z predykcją")
    y = dpcmPredict(sound, 8, 4)
    y = dpcmPredictDecode(y, 4)
    sd.play(y, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

def soundTest8to2bits(files):
  for file in files:
    sound, fs = sf.read(file)

    print("File: " + file)
    sd.play(sound, fs)
    status = sd.wait()

    x = input("Press Enter to continue...")

    for i in range(8, 1, -1):
      print("A-law " + str(i) + " bit")
      y = alaw(sound)
      y = kwant(y, i)
      y = decodeAlaw(y)
      sd.play(y, fs)
      status = sd.wait()

      x = input("Press Enter to continue...")

    for i in range(8, 1, -1):
      print("Mu-law " + str(i) + " bit")
      y = ulaw(sound)
      y = kwant(y, i)
      y = decodeUlaw(y)
      sd.play(y, fs)
      status = sd.wait()

      x = input("Press Enter to continue...")

    for i in range(8, 1, -1):
      print("DPCM " + str(i) + " bit")
      y = dpcmNoPredict(sound, i)
      y = dpcmNoPredictDecode(y)
      sd.play(y, fs)
      status = sd.wait()

      x = input("Press Enter to continue...")

    for i in range(8, 1, -1):
      print("DPCM z predykcją " + str(i) + " bit")
      y = dpcmPredict(sound, i, 4)
      y = dpcmPredictDecode(y, 4)
      sd.play(y, fs)
      status = sd.wait()

      x = input("Press Enter to continue...")

files = ['SING/sing_low1.wav', 'SING/sing_medium1.wav', 'SING/sing_high1.wav']

#lawGraphs()
#dpcmLawGraphs()

#soundTest8bits(files)
soundTest8to2bits(files)