import matplotlib.pyplot as plt
import numpy as np
import os

data_sin = []
data_ma_a = []
data_w_ma_a = []
data_ma_b = []
data_w_ma_b = []
data_ma_c = []
data_w_ma_c = []
data_pm_a = []
data_w_pm_a = []
data_pm_b = []
data_w_pm_b = []
data_pm_c = []
data_w_pm_c = []
data_fm_a = []
data_w_fm_a = []
data_fm_b = []
data_w_fm_b = []
data_fm_c = []
data_w_fm_c = []
time = []

with open(os.path.join(os.path.dirname(__file__), "sinus.txt")) as f:
	for y in f.readlines():
		data_sin.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "ma_a.txt")) as f:
	for y in f.readlines():
		data_ma_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_ma_a.txt")) as f:
	for y in f.readlines():
		data_w_ma_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "ma_b.txt")) as f:
	for y in f.readlines():
		data_ma_b.append(float(y))
	
with open(os.path.join(os.path.dirname(__file__), "w_ma_b.txt")) as f:
	for y in f.readlines():
		data_w_ma_b.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "ma_c.txt")) as f:
	for y in f.readlines():
		data_ma_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_ma_c.txt")) as f:
	for y in f.readlines():
		data_w_ma_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "pm_a.txt")) as f:
	for y in f.readlines():
		data_pm_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_pm_a.txt")) as f:
	for y in f.readlines():
		data_w_pm_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "pm_b.txt")) as f:
	for y in f.readlines():
		data_pm_b.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_pm_b.txt")) as f:
	for y in f.readlines():
		data_w_pm_b.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "pm_c.txt")) as f:
	for y in f.readlines():
		data_pm_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_pm_c.txt")) as f:
	for y in f.readlines():
		data_w_pm_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "fm_a.txt")) as f:
	for y in f.readlines():
		data_fm_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_fm_a.txt")) as f:
	for y in f.readlines():
		data_w_fm_a.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "fm_b.txt")) as f:
	for y in f.readlines():
		data_fm_b.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_fm_b.txt")) as f:
	for y in f.readlines():
		data_w_fm_b.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "fm_c.txt")) as f:
	for y in f.readlines():
		data_fm_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "w_fm_c.txt")) as f:
	for y in f.readlines():
		data_w_fm_c.append(float(y))

with open(os.path.join(os.path.dirname(__file__), "t.txt")) as f:
	for y in f.readlines():
		time.append(float(y))

plt.plot(time, data_sin, 'r-', label='sin(t)')
plt.title('fsin(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'sin.png'))
plt.show()

plt.plot(time, data_ma_a, 'r-', label='ma_a(t)')
plt.title('ma_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'ma_a.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_ma_a, 'r-', label='w_ma_a(t)')
plt.title('w_ma_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_ma_a.png'))
plt.show()

plt.plot(time, data_ma_b, 'r-', label='ma_b(t)')
plt.title('ma_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'ma_b.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_ma_b, 'r-', label='w_ma_b(t)')
plt.title('w_ma_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_ma_b.png'))
plt.show()

plt.plot(time, data_ma_c, 'r-', label='ma_c(t)')
plt.title('ma_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'ma_c.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_ma_c, 'r-', label='w_ma_c(t)')
plt.title('w_ma_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_ma_c.png'))
plt.show()

plt.plot(time, data_pm_a, 'r-', label='pm_a(t)')
plt.title('pa_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'pm_a.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_pm_a, 'r-', label='w_pm_a(t)')
plt.title('w_pm_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_pm_a.png'))
plt.show()

plt.plot(time, data_pm_b, 'r-', label='pm_b(t)')
plt.title('pm_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'pm_b.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_pm_b, 'r-', label='w_pm_b(t)')
plt.title('w_pm_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_pm_b.png'))
plt.show()

plt.plot(time, data_pm_c, 'r-', label='pm_c(t)')
plt.title('pm_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'pm_c.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_pm_c, 'r-', label='w_pm_c(t)')
plt.title('w_pm_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_pm_c.png'))
plt.show()

plt.plot(time, data_fm_a, 'r-', label='fm_a(t)')
plt.title('fm_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'fm_a.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_fm_a, 'r-', label='w_fm_a(t)')
plt.title('w_fm_a(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_fm_a.png'))
plt.show()

plt.plot(time, data_fm_b, 'r-', label='fm_b(t)')
plt.title('fm_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'fm_b.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_fm_b, 'r-', label='w_fm_b(t)')
plt.title('w_fm_b(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_fm_b.png'))
plt.show()

plt.plot(time, data_fm_c, 'r-', label='fm_c(t)')
plt.title('fm_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'fm_c.png'))
plt.show()

plt.plot(time[:len(time) // 2 - 1], data_w_fm_c, 'r-', label='w_fm_c(t)')
plt.title('w_fm_c(t)')
plt.savefig(os.path.join(os.path.dirname(__file__),'w_fm_c.png'))
plt.show()