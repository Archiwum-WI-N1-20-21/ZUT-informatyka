#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
	int nrIndexu;
public:
	Student() {};
	~Student() {};

	void setNrIndexu(int nr) {
		nrIndexu = nr;
	}

	void wyswietlNrIndexu() {
		cout << "Numer indexu: " << nrIndexu << endl;
	}

	int getNrIndexu() {
		return nrIndexu;
	}
};

class Kolokwium: virtual public Student
{
protected:
	double wynikKol1, wynikKol2, wynikKol3;
public:
	void wyswietlWynikiKolokwium() {
		cout << "Kolokwium 1: " << wynikKol1 << endl << "Kolokwium 2: " << wynikKol2 << endl << "Kolokwium 3: " << wynikKol3 << endl;
	}

	void setWynikiKolokwium(double wynik1, double wynik2, double wynik3) {
		wynikKol1 = wynik1;
		wynikKol2 = wynik2;
		wynikKol3 = wynik3;
	}


};

class Egzamin: virtual public Student
{
protected:
	double wynikEgzaminu;
public:
	Egzamin() {};
	~Egzamin() {};

	void wyswietlWynikEgzaminu() {
		cout << "Wynik egzaminu: " << wynikEgzaminu << endl;
	}

	void setWynikEgzaminu(double wynik) {
		wynikEgzaminu = wynik;
	}
	double getWynikEgzaminu() {
		return wynikEgzaminu;
	}
};

class Wynik: virtual public Kolokwium, virtual public Egzamin
{
private:
	double wynikStudenta;
public:
	void wyswietlWynikStudenta() {
		cout << "Wynik studenta: " << wynikStudenta << endl;
	}

	void obliczWynik() {
		wynikStudenta = (wynikKol1 + wynikKol2 + wynikKol3) / 3 + 3 * wynikEgzaminu;
	}
};


int main() {
	// Statycznie
	Wynik studentStatyczny;
	studentStatyczny.setNrIndexu(1);
	studentStatyczny.setWynikiKolokwium(13.2,8.6,10.6);
	studentStatyczny.setWynikEgzaminu(12.2);
	studentStatyczny.obliczWynik();

	// Printy
	studentStatyczny.wyswietlNrIndexu();
	studentStatyczny.wyswietlWynikiKolokwium();
	studentStatyczny.wyswietlWynikEgzaminu();
	studentStatyczny.wyswietlWynikStudenta();

	cout << "========================" << endl;

	// Dynamicznie
	Wynik * studentDynamiczny = new Wynik;
	studentDynamiczny->setNrIndexu(2);
	studentDynamiczny->setWynikiKolokwium(10.2,11.0,8.3);
	studentDynamiczny->setWynikEgzaminu(10.8);
	studentDynamiczny->obliczWynik();

	// Printy
	studentDynamiczny->wyswietlNrIndexu();
	studentDynamiczny->wyswietlWynikiKolokwium();
	studentDynamiczny->wyswietlWynikEgzaminu();
	studentDynamiczny->wyswietlWynikStudenta();

	delete studentDynamiczny;


	return 0;
}