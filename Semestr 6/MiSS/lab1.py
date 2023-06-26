import scipy.interpolate as interpolate
import numpy as np
import matplotlib.pyplot as plt

# zad1
x = [-3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0]
y = [-0.16, -0.2, 0.6, 0.9, 0.35, -0.25, 0, 0.25, -0.38, -1, -0.6, 0.2, 0.18]

# zad2 point -1.25
x_z2 = -1.25
y_z2 = 0.7

f1 = interpolate.interp1d(x, y, kind="nearest")
y1p = f1(x_z2)
err1 = abs(y_z2 - y1p)

f2 = interpolate.interp1d(x, y, kind="linear")
y2p = f2(x_z2)
err2 = abs(y_z2 - y2p)

f3 = interpolate.interp1d(x, y, kind="quadratic")
y3p = f3(x_z2)
err3 = abs(y_z2 - y3p)

f4 = interpolate.interp1d(x, y, kind="cubic")
y4p = f4(x_z2)
err4 = abs(y_z2 - y4p)

# najlepsza metoda to cubic

# zad3
x_z3 = np.linspace(-3, 3, 1000)
y1_z3 = f1(x_z3)
y2_z3 = f2(x_z3)
y3_z3 = f3(x_z3)
y4_z3 = f4(x_z3)

plt.plot(x, y, 'o')
plt.plot(x_z3, y1_z3, label='nearest')
plt.plot(x_z3, y2_z3, label='linear')
plt.plot(x_z3, y3_z3, label='quadratic')
plt.plot(x_z3, y4_z3, label='cubic')
plt.legend(loc="upper left")
#plt.show()

# najlepsza metoda to ponownie cubic

# zad4
x_z4 = x_z3
for i in range(12):
	pp = np.polyfit(x, y, i)
	yy = np.polyval(pp, x_z4)

	plt.plot(x, y, 'o')
	plt.plot(x_z4, yy, label='polyfit')
	plt.title(str(i))
	mean = np.mean((x_z4 - np.polyval(pp, x_z4))**2)
	print([i, mean])
	#plt.show()

# najlepsza metoda to 11

# zad5
x_z5 = x_z4
pp = np.polyfit(x, y, 11)
yy = np.polyval(pp, x_z2)
err = abs(y_z2 - yy)
print(err)