import matplotlib.pyplot as plt
import numpy as np
import os

datau = []
time = []

with open(os.path.join(os.path.dirname(__file__), "dump1fu.txt")) as f:
	for y in f.readlines():
		datau.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t.txt")) as f:
	for y in f.readlines():
		time.append(float(y))

plt.plot(time, datau, 'r-', label='u(t)')
plt.title('u(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'u.png'))
plt.show()