import matplotlib.pyplot as plt
import numpy as np
import os

datasin = []
time = []
dataAS = []
dataASdb = []

with open(os.path.join(os.path.dirname(__file__), "sinus.txt")) as f:
	for y in f.readlines():
		datasin.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "t.txt")) as f:
	for y in f.readlines():
		time.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "AS.txt")) as f:
	for y in f.readlines():
		dataAS.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "ASdb.txt")) as f:
	for y in f.readlines():
		dataASdb.append(float(y))

plt.plot(time, datasin, 'r-', label='sin(t)')
plt.title('sin(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'sin.png'))
plt.show()

plt.plot(time[0:int(len(time) / 2 - 1)], dataAS, 'r-', label='AS(k)')
plt.title('AS(k)')
plt.savefig(os.path.join(os.path.dirname(__file__),'AS.png'))
plt.show()

plt.plot(time[0:int(len(time) / 2 - 1)], dataASdb, 'r-', label='ASdb(k)')
plt.title('ASdb(k)')
plt.savefig(os.path.join(os.path.dirname(__file__),'ASdb.png'))
plt.show()