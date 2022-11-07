#zad1
from collections import namedtuple
trojkat = namedtuple('trojkat', ['a', 'h'])

def pole_trojkata(trojkat):
    pole = (1/2*trojkat.a)*trojkat.h
    return pole


print(pole_trojkata(trojkat(3,6)))

#zad2
import random

lista = []
for i in range(100):
	lista.append(random.randrange(1,199,2))

zbior = set(lista)
print("\nZbior:")
print(zbior)

#zad3
from collections import Counter
print("\nSlownik:")
print(Counter(lista))
