import matplotlib.pyplot as plt
import numpy as np
import os

data = []
time = []

with open(os.path.join(os.path.dirname(__file__), "dump1f.txt")) as f:
	for y in f.readlines():
		data.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t.txt")) as f:
	for y in f.readlines():
		time.append(float(y))

plt.plot(time, data, 'r-', label='x(t)')

plt.title('x(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'x.png'))