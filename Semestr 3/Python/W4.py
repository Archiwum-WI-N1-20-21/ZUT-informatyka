#zad1
import numpy as np

v = 6 ** np.arange(400, dtype=np.int64)
print(v)

#zad2
def zad2(n):
	A = np.ones((n,n))
	for i in range(n):
		for j in range(1,n):
			A[i,j] = (2*i-1)**(j*6)
	return A

print(zad2(10))

#zad3
from scipy import interpolate

lata = np.array([2001, 2002, 2005, 2006, 2008, 2010])
ceny = np.array([0.36, 0.38, 0.42, 0.44, 0.5, 0.55])

f = interpolate.interp1d(lata, ceny, kind = "cubic")
print(f([2004]))