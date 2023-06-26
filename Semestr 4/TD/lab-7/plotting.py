import matplotlib.pyplot as plt
import numpy as np
import os
import sys

def plotting(data, name, time):
	plt.figure()
	tit = name.strip('.txt') + "(t)"
	plt.title(tit)
	plt.plot(time, data)
	plt.grid()
	if sys.argv[3] == "1":
		plt.savefig(os.path.join(os.path.dirname(__file__), 'graphs', name.strip('.txt') + '.png'))
	if sys.argv[2] == "1":
		plt.show()

def read_data(data_array, name):
	with open(os.path.join(os.path.dirname(__file__), 'dumps', name)) as f:
		for y in f.readlines():
			data_array.append(float(y))

time = []
data = []

read_data(time, "time.txt")
read_data(data, sys.argv[1])
plotting(data, sys.argv[1], time)