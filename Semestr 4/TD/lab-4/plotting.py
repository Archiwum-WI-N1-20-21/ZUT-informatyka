from unicodedata import name
import matplotlib.pyplot as plt
import numpy as np
import os

def plotting(data, name):
	plt.figure()
	tit = name + "(t)"
	plt.title(tit)
	plt.plot(time, data)
	plt.grid()
	plt.savefig(os.path.join(os.path.dirname(__file__), name + '.png'))
	plt.show()

def plotting_half_time(data, name):
	plt.figure()
	tit = name + "(t)"
	plt.title(tit)
	plt.plot(time[:len(time) // 2 - 1], data)
	plt.grid()
	plt.savefig(os.path.join(os.path.dirname(__file__), name + '.png'))
	plt.show()

def read_data(d, n):
	with open(os.path.join(os.path.dirname(__file__), n + '.txt')) as f:
		for y in f.readlines():
			d.append(float(y))

ask = []
psk = []
fsk = []
ask_db = []
psk_db = []
fsk_db = []
time = []

data = [ask, ask_db, psk, psk_db, fsk, fsk_db, time]
names = ["ask", "ask_db", "psk", "psk_db", "fsk", "fsk_db", "time"]

for i in range(len(data)):
	read_data(data[i], names[i])

for i in range(len(data) - 1):
	if i % 2 == 0:
		plotting(data[i], names[i])
	else:
		plotting_half_time(data[i], names[i])