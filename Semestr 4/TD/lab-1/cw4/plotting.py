import matplotlib.pyplot as plt
import numpy as np
import os

datab1 = []
datab2 = []
datab3 = []
time1 = [0.0]
time2 = [0.0]
time3 = [0.0]
#[datab3.append(float(y) for y in f.readlines() if float(y) > 0.0)]

with open(os.path.join(os.path.dirname(__file__), "dump1b1.txt")) as f:
	for y in f.readlines():
		datab1.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1b2.txt")) as f:
	for y in f.readlines():
		datab2.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1b3.txt")) as f:
	for y in f.readlines():
		datab3.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t1.txt")) as f:
	for y in f.readlines():
		time1.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t2.txt")) as f:
	for y in f.readlines():
		time2.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "dump1t3.txt")) as f:
	for y in f.readlines():
		time3.append(float(y))

time1.pop(0)
time2.pop(0)
time3.pop(0)

plt.plot(time1, datab1, 'r-', label='b1(t)')
plt.title('b1(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'b1.png'))
plt.show()

plt.plot(time2, datab2, 'r-', label='b2(t)')
plt.title('b2(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'b2.png'))
plt.show()

plt.plot(time3, datab3, 'r-', label='b3(t)')
plt.title('b3(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'b3.png'))
plt.show()