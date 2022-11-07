#include <iostream>
#include <math.h>

class Figura
{
public:
	int r, h1, h2;

	Figura(int, int , int );
	Figura();

	double oblicz_powierzchnie()
	{
		double l = sqrt(pow(h2, 2) + r);
		double gora = M_PI * r * l;

		double srodek = 2 * M_PI * r * h1;

		double dol = 4 * M_PI * pow(r, 3);

		return gora + srodek + (dol / 2);
	}

	double oblicz_objetosc()
	{
		double gora = (M_PI * pow(r, 2) * h2) / 3;
		
		double srodek = M_PI * pow(r, 2) * h1;
		
		double dol = (4 / 3) * M_PI * pow(r, 3);

		return gora + srodek + (dol / 2);
	}
};

Figura::Figura(int _r, int _h1, int _h2)
{
	r = _r;
	h1 = _h1;
	h2 = _h2;
}

Figura::Figura()
{
	r = 101;
	h1 = 102;
	h2 = 103;
}


using namespace std;

int main() {
	Figura figura1(101, 102, 103);
	Figura figura2(11, 12, 13);
	Figura figura3;
	Figura * figura4 = new Figura(21, 20, 19);

	cout << "Powierzchnia figury 1: " << figura1.oblicz_powierzchnie() << endl;
	cout << "Objetosc figury 1: " << figura1.oblicz_objetosc() << endl << endl;
	cout << "Powierzchnia figury 2: " << figura2.oblicz_powierzchnie() << endl;
	cout << "Objetosc figury 2: " << figura2.oblicz_objetosc() << endl << endl;
	cout << "Powierzchnia figury 3: " << figura3.oblicz_powierzchnie() << endl;
	cout << "Objetosc figury 3: " << figura3.oblicz_objetosc() << endl << endl;
	cout << "Powierzchnia figury 4: " << figura4->oblicz_powierzchnie() << endl;
	cout << "Objetosc figury 4: " << figura4->oblicz_objetosc();

	delete figura4;

	return 0;
}