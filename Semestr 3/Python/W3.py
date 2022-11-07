#zad1

class A:
    def __init__(self, a, b):
        self.a = a
        self.__b = b
        if (a < b):
            raise ValueError

    def get_b(self):
        return self.__b

    def set_b(self, val):
        self.__b = val

#zad2

class B:
    def __init__(self, a, b):
        self.a = a
        self.__b = b

    @property
    def b(self):
        return self.__b

    @b.setter
    def b(self, val):
        if (val > (self.a**3)):
            self.__b = self.a
        else:
            self.__b = val

clb = B(5,6)
clb.b = 200
print(clb.b)

#zad3
from abc import abstractmethod

class Zabawka:
    def __init__(self, cena):
        self.cena = cena
    
    @abstractmethod
    def nazwa(self):
        pass


class Gra(Zabawka):
    def __init__(self):
        super().__init__(50)
        self.typ = "Gra"

    def nazwa(self):
        super().nazwa()
        print(self.typ)

cgra = Gra()
cgra.nazwa()
