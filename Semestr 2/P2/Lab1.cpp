#include <iostream>

using namespace std;

struct zespolona {
                 double rzeczywista;
                 double urojona;
};

void pobierzDane(struct zespolona*);
void wyswietlWynik(struct zespolona);
struct zespolona suma(struct zespolona, struct zespolona);
struct zespolona roznica(struct zespolona, struct zespolona);
struct zespolona iloczyn(struct zespolona, struct zespolona);
struct zespolona iloraz(struct zespolona, struct zespolona);
struct zespolona sprzezona(struct zespolona);

void pobierzDane(struct zespolona* z) {
	cout << "Podaj liczbe rzeczywista: ";
	cin >> z->rzeczywista;
	cout << "Podaj liczbe urojona: ";
	cin >> z->urojona;
}

void wyswietlWynik(struct zespolona z) {
	cout << z.rzeczywista << " + " << z.urojona << "i" << endl;
}

zespolona suma(struct zespolona z1, struct zespolona z2) {
	zespolona z3;
	z3.rzeczywista = z1.rzeczywista + z2.rzeczywista;
	z3.urojona = z1.urojona + z2.urojona;
	return z3;
}

struct zespolona roznica(struct zespolona z1, struct zespolona z2) {
	zespolona z4;
	z4.rzeczywista = z1.rzeczywista - z2.rzeczywista;
	z4.urojona = z1.urojona - z2.urojona;
	return z4;
}

struct zespolona iloczyn(struct zespolona z1, struct zespolona z2) {
	zespolona z5;
	z5.rzeczywista = (z1.rzeczywista * z2.rzeczywista) - (z1.urojona * z2.urojona);
	z5.urojona = (z1.rzeczywista * z2.urojona) + (z1.urojona * z2.rzeczywista);
	return z5;
}

struct zespolona iloraz(struct zespolona z1, struct zespolona z2) {
	zespolona z6;
	z6.rzeczywista = (((z1.rzeczywista * z2.rzeczywista) + (z1.urojona * z2.urojona)) / ((z2.rzeczywista * z2.rzeczywista) + (z2.urojona * z2.urojona)));
	z6.urojona = (((z1.urojona * z2.rzeczywista) - (z1.rzeczywista * z2.urojona)) / ((z2.rzeczywista * z2.rzeczywista) + (z2.urojona * z2.urojona)));
	return z6;
}

struct zespolona sprzezona(struct zespolona z) {
	zespolona z7;
	z7.rzeczywista = z.rzeczywista;
	z7.urojona = z.urojona * -1;
	return z7;
}

int main() {
	struct zespolona z1, z2;

	pobierzDane(&z1);
	pobierzDane(&z2);

	cout << endl << "Suma: ";
	wyswietlWynik(suma(z1, z2));
	cout << "Roznica: ";
	wyswietlWynik(roznica(z1, z2));
	cout << "Iloczyn: ";
	wyswietlWynik(iloczyn(z1, z2));
	cout << "Iloraz: ";
	wyswietlWynik(iloraz(z1, z2));
	cout << "Sprzezona 1: ";
	wyswietlWynik(sprzezona(z1));
	cout << "Sprzezona 2: ";
	wyswietlWynik(sprzezona(z2));
}