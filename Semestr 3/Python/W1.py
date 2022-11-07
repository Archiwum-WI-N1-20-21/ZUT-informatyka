#zad 1
print("zadanie 1\n")

liczbaA = int(input("Podaj liczbe A: "))
liczbaB = int(input("Podaj liczbe B: "))

if liczbaA == liczbaB:
	print("liczby sa identyczne")
if liczbaA % liczbaB == 0:
	print("l1 jest wielokrotnoscia l2")
elif liczbaB % liczbaA == 0:
	print("l2 jest wielokrotnosica l1")
else:
	print("liczby nie sa swoimi wielokrotnosciami")

#zad 2
print("\nzadanie 2\n")

def seqenceO(n):
	if n == 1:
		return 2
	if n == 2:
		return 3
	if n > 2:
		return 2 * seqenceO(n - 1)

print(seqenceO(5))

#zad 3
import math as m
print("\nzadanie 3\n")

def equation(x, k = 2, p = 4):
	f = (-2 * m.log(x, k)) + (m.sin(x))**p
	return f

print(equation(x = 10,p = 2))