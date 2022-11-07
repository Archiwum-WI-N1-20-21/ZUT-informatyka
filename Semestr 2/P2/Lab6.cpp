#include <iostream>
#include <string>

using namespace std;

class Wieloscian
{
protected:
	double dlugoscPodstawy, szerokoscPodstawy, wysokosc;
public:
	Wieloscian() {};
	~Wieloscian() {};

	double setDlugosc(double dlugosc) {
		dlugoscPodstawy = dlugosc;
	}

	double setSzczerokosc(double szerokosc) {
		szerokoscPodstawy = szerokosc;
	}

	double setWysokosc(double _wysokosc) {
		wysokosc = _wysokosc;
	}
};

class Prostopadloscian: public Wieloscian
{
public:
	double Objetosc() {
		double V = dlugoscPodstawy * szerokoscPodstawy * wysokosc;
		return V;
	}

	double Pole() {
		double P = 2 * (dlugoscPodstawy * szerokoscPodstawy + dlugoscPodstawy * wysokosc + szerokoscPodstawy * wysokosc);
		return P;
	}
};

class Ostroslup: public Wieloscian
{
public:
	double Objetosc() {
		double V = (dlugoscPodstawy * szerokoscPodstawy) * wysokosc * 1/3;
		return V;
	}

	double Pole() {
		double P = (dlugoscPodstawy * szerokoscPodstawy) + 2 * (1/2 * dlugoscPodstawy * wysokosc) + 2 * (1/2 * szerokoscPodstawy * wysokosc);
		return P;
	}
};

int main() {
	// Statycznie
	Prostopadloscian prostopadloscian;
	Ostroslup ostroslup;

	prostopadloscian.setDlugosc(15);
	prostopadloscian.setSzczerokosc(10);
	prostopadloscian.setWysokosc(4);

	ostroslup.setDlugosc(12);
	ostroslup.setSzczerokosc(12);
	ostroslup.setWysokosc(4);

	cout << "Objetosc prostopadloscianu: " << prostopadloscian.Objetosc() << endl;
	cout << "Pole prostopadloscianu: " << prostopadloscian.Pole() << endl;

	cout << "Objetosc ostroslupa: " << ostroslup.Objetosc() << endl;
	cout << "Pole ostroslupa: " << ostroslup.Pole() << endl;
	

	// Dynamicznie
	Prostopadloscian * prostopadloscianD = new Prostopadloscian();
	Ostroslup * ostroslupD = new Ostroslup();

	prostopadloscianD->setDlugosc(15);
	prostopadloscianD->setSzczerokosc(10);
	prostopadloscianD->setWysokosc(4);

	ostroslupD->setDlugosc(12);
	ostroslupD->setSzczerokosc(12);
	ostroslupD->setWysokosc(4);

	cout << "Objetosc prostopadloscianu dynamicznego: " << prostopadloscianD->Objetosc() << endl;
	cout << "Pole prostopadloscianu dynamicznego: " << prostopadloscianD->Pole() << endl;

	cout << "Objetosc ostroslupa dynamicznego: " << ostroslupD->Objetosc() << endl;
	cout << "Pole ostroslupa dynamicznego: " << ostroslupD->Pole() << endl;

	delete prostopadloscianD;
	delete ostroslupD;

	return 0;
}