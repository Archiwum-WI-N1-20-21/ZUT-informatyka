#include <iostream>
#include <string>

using namespace std;

class Zespolona
{
private:
	double czesc_rzeczywista, czesc_urojona;
public:
	Zespolona() {
		czesc_rzeczywista = 0;
		czesc_urojona = 0;
	}
	Zespolona(double a, double b) {
	czesc_rzeczywista = a;
	czesc_urojona = b;
	}
	~Zespolona() {};

	void wyswietl() {
		if (czesc_urojona > 0) {
			cout << "z = " << czesc_rzeczywista << " + " << czesc_urojona << "i" << endl;
		} else {
			cout << "z = " << czesc_rzeczywista << " - " << czesc_urojona * -1 << "i" << endl;
		}
	}

	// Przeciazenie new i delete
	void * operator new (size_t size) {
		void * p = malloc(size);
		return p;
	}

	void operator delete (void * p) {
		free(p);
	}

	friend Zespolona operator + (const Zespolona &z1, const Zespolona &z2);
	friend Zespolona operator - (const Zespolona &z1, const Zespolona &z2);
	friend Zespolona operator * (const Zespolona &z1, const Zespolona &z2);
	friend Zespolona operator / (const Zespolona &z1, const Zespolona &z2);
};

// Przeciazenia operatorow arytmetycznych
Zespolona operator + (const Zespolona &z1, const Zespolona &z2) {
	Zespolona z(z1.czesc_rzeczywista + z2.czesc_rzeczywista, z1.czesc_urojona + z2.czesc_urojona);
	return z;
}

Zespolona operator - (const Zespolona &z1, const Zespolona &z2) {
	Zespolona z(z1.czesc_rzeczywista - z2.czesc_rzeczywista, z1.czesc_urojona - z2.czesc_urojona);
	return z;
}

Zespolona operator * (const Zespolona &z1, const Zespolona &z2) {
	Zespolona z(z1.czesc_rzeczywista * z2.czesc_rzeczywista - z1.czesc_urojona * z2.czesc_urojona, z1.czesc_urojona * z2.czesc_rzeczywista + z2.czesc_urojona * z1.czesc_rzeczywista);
	return z;
}

Zespolona operator / (const Zespolona &z1, const Zespolona &z2) {
	Zespolona z((z1.czesc_rzeczywista * z2.czesc_rzeczywista + z1.czesc_urojona * z2.czesc_urojona) / (z2.czesc_rzeczywista * z2.czesc_rzeczywista + z2.czesc_urojona * z2.czesc_urojona), (z1.czesc_rzeczywista * z2.czesc_urojona - z1.czesc_urojona * z2.czesc_rzeczywista) / (z2.czesc_rzeczywista * z2.czesc_rzeczywista + z2.czesc_urojona * z2.czesc_urojona));
	return z;
}

int main() {
	// Statycznie
	Zespolona z1(5,3);
	Zespolona z2(2,8);

	z1.wyswietl();
	z2.wyswietl();

	Zespolona zDodawanie = z1 + z2;
	Zespolona zOdejmowanie = z1 - z2;
	Zespolona zMnozenie = z1 * z2;
	Zespolona zDzielenie = z1 / z2;

	zDodawanie.wyswietl();
	zOdejmowanie.wyswietl();
	zMnozenie.wyswietl();
	zDzielenie.wyswietl();

	// Dynamicznie
	Zespolona * z1D = new Zespolona(2,3);
	Zespolona * z2D = new Zespolona(6,1);

	z1D->wyswietl();
	z2D->wyswietl();

	Zespolona * zDodawanieD = new Zespolona();
	Zespolona * zOdejmowanieD = new Zespolona();
	Zespolona * zMnozenieD = new Zespolona();
	Zespolona * zDzielenieD = new Zespolona();

	*zDodawanieD = *z1D + *z2D;
	zDodawanieD->wyswietl();

	*zOdejmowanieD = *z1D - *z2D;
	zOdejmowanieD->wyswietl();

	*zMnozenieD = *z1D * *z2D;
	zMnozenieD->wyswietl();

	*zDzielenieD = *z1D / *z2D;
	zDzielenieD->wyswietl();

	delete z1D;
	delete z2D;
	delete zDodawanieD;
	delete zOdejmowanieD;
	delete zMnozenieD;
	delete zDzielenieD;

	return 0;
}