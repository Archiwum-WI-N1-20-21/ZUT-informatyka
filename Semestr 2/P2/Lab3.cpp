#include <iostream>
using namespace std; 

class Pierwsza {
	private:
	int a;

	public:
		Pierwsza() {a = 150;}
		friend class Druga;
};

class Druga {
	private:
	int b;

	public:
	Druga() {
		b = 20;
	}

	int dodajAiB(Pierwsza& a, Druga& b) {
		return a.a + b.b;
	}

};

int main() {
	Pierwsza pierwsza;
	Druga druga;

	int wynik = druga.dodajAiB(pierwsza, druga);

	cout << "Wynik: " << wynik << endl;

	return 0;
}