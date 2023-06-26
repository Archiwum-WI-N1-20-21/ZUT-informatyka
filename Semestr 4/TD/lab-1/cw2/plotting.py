import matplotlib.pyplot as plt
import numpy as np
import os

datay = []
datav = []
dataz = []
time = []

with open(os.path.join(os.path.dirname(__file__), "dump1fy.txt")) as f:
	for y in f.readlines():
		datay.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1fv.txt")) as f:
	for y in f.readlines():
		datav.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1fz.txt")) as f:
	for y in f.readlines():
		dataz.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t.txt")) as f:
	for y in f.readlines():
		time.append(float(y))

plt.plot(time, datay, 'r-', label='y(t)')
plt.title('y(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'y.png'))
plt.show()

plt.plot(time, datav, 'r-', label='v(t)')
plt.title('v(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'v.png'))
plt.show()

plt.plot(time, dataz, 'r-', label='z(t)')
plt.title('z(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'z.png'))
plt.show()