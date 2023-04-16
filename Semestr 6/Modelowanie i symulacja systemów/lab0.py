import numpy as np
import matplotlib.pyplot as plt

#zad1
f1 = lambda x: np.sin(x) + np.cos(x)
f2 = lambda x: np.exp(x) + np.log(x)
f3 = lambda x, y: np.sin(x) + np.cos(y)

#zad2
x = np.linspace(0, 4, 1000)

plt.plot(x, f1(x), label='f1')
plt.plot(x, f2(x), label='f2')
plt.legend(loc="upper left")
plt.show()

#zad3
x3 = np.linspace(-2 * np.pi, 2 * np.pi, 1000)
y3 = np.linspace(-2 * np.pi, 2 * np.pi, 1000)
X, Y = np.meshgrid(x3, y3)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, f3(X, Y))
plt.show()

#zad4
vec_x = np.random.rand(7) * 3 + 2
vec_y = np.random.rand(7) * 3 + 2

def zad4():
    plt.plot(vec_x, vec_y, 'rs', markersize=15)
    plt.plot(vec_x, vec_y, 'k--', lw=3)
    plt.show()

zad4()