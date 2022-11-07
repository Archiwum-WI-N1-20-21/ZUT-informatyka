#include <iostream>
#include <string>

using namespace std;

class Pies
{
private:
	string imie, rasa, plec;
	int wiek;
	double waga;
	float wielkosc;

public:
	Pies(string, string, string, int, double, float);

	// settery
	void setImie(string _imie) {
		imie = _imie;
	}
	void setPlec(string _plec) {
		plec = _plec;
	}
	void setRasa(string _rasa) {
		rasa = _rasa;
	}
	void setWiek(int _wiek) {
		wiek = _wiek;
	}
	void setWaga(double _waga) {
		waga = _waga;
	}
	void setWielkosc(float _wielkosc) {
		wielkosc = _wielkosc;
	}

	// gettery
	string getImie() {
		return imie;
	}
	string getPlec() {
		return plec;
	}
	string getRasa() {
		return rasa;
	}
	int getWiek() {
		return wiek;
	}
	double getWaga() {
		return waga;
	}
	float getWielkosc() {
		return wielkosc;
	}
};

Pies::Pies(string _imie, string _plec, string _rasa, int _wiek, double _waga, float _wielkosc)
{
	setImie(_imie);
	setPlec(_plec);
	setRasa(_rasa);
	setWiek(_wiek);
	setWaga(_waga);
	setWielkosc(_wielkosc);
}

int main() {
	Pies piesStatyczny("Jacek", "M", "Jamnik", 3, 15.03, 153.21);
	cout << "Pies statyczny:" << endl << piesStatyczny.getImie() << endl << piesStatyczny.getPlec() << endl << piesStatyczny.getRasa() << endl << piesStatyczny.getWiek() << endl << piesStatyczny.getWaga() << endl << piesStatyczny.getWielkosc() << endl << endl;

	piesStatyczny.setImie("Maciek");
	piesStatyczny.setPlec("F");
	piesStatyczny.setRasa("Owczarek");
	piesStatyczny.setWiek(5);
	piesStatyczny.setWaga(20.52);
	piesStatyczny.setWielkosc(140.12);
	cout << "Po zmianach: " << endl << "Pies statyczny:" << endl << piesStatyczny.getImie() << endl << piesStatyczny.getPlec() << endl << piesStatyczny.getRasa() << endl << piesStatyczny.getWiek() << endl << piesStatyczny.getWaga() << endl << piesStatyczny.getWielkosc() << endl << endl;

	Pies * piesDynamiczny = new Pies("Basia", "M", "Owczarek", 6, 45.12, 250.56);
	cout << "Pies dynamiczny:" << endl << piesDynamiczny->getImie() << endl << piesDynamiczny->getPlec() << endl << piesDynamiczny->getRasa() << endl << piesDynamiczny->getWiek() << endl << piesDynamiczny->getWaga() << endl << piesDynamiczny->getWielkosc() << endl << endl;
	
	piesDynamiczny->setImie("Barbara");
	piesDynamiczny->setPlec("F");
	piesDynamiczny->setRasa("Bernadryn");
	piesDynamiczny->setWiek(2);
	piesDynamiczny->setWaga(80.45);
	piesDynamiczny->setWielkosc(300.21);
	cout << "Po zmianach:" << endl << "Pies dynamiczny:" << endl << piesDynamiczny->getImie() << endl << piesDynamiczny->getPlec() << endl << piesDynamiczny->getRasa() << endl << piesDynamiczny->getWiek() << endl << piesDynamiczny->getWaga() << endl << piesDynamiczny->getWielkosc() << endl << endl;

	delete piesDynamiczny;
	return 0;
}