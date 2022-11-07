import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

#zad 1
x = np.linspace(-3, 5, 50)
x1 = np.linspace(-3, 5, 11)

y = pow(x, 3) - (3 * pow(x, 2)) - (6 * x) + 8
y1 = np.fabs(pow(x1, 3) - (3 * pow(x1, 2)) - (6 * x1) + 8)

plt.plot(x, y, "r", lw=2.0, label="f1")
plt.plot(x1, y1, "k.", lw=2.0, label="f2")
plt.legend(loc='upper left', frameon=False)
plt.title("Zadanie 1")
plt.show()

#zad 2
x = np.linspace(-2, 2, 40)
y = np.fabs(x)
y1 = np.fabs(x) - 1
y2 = np.fabs(x - 1)

fig, (ax1, ax2, ax3) = plt.subplots(1, 3)
fig.suptitle("Zadanie 2")
ax1.plot(x, y, "r")
ax2.plot(x, y1, "b")
ax3.plot(x, y2, "g")
plt.show()

#zad 3
x = np.arange(-1.1, 1.1, 0.05)
y = np.arange(-2.2, 0.2, 0.1)

z = pow(x, 3) + 2 * y + pow(y, 2) - 1

fig = plt.figure()
ax = fig.gca(projection="3d")
X, Y = np.meshgrid(x, y)

ax.plot_surface(X, Y, z, cmap=cm.pubugn)
plt.show()