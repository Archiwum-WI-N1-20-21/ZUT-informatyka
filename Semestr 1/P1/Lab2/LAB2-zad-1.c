#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	// PIERWSZA CZESC (1.1)
	float x, y, z, m;

	printf("Wprowadz x: "); // Zapytania o wprowadzenie wartosci do obliczenia m
	scanf_s("%f", &x);
	printf("Wprowadz y: ");
	scanf_s("%f", &y);
	printf("Wprowadz z: ");
	scanf_s("%f", &z);

	m = (fminf(x + y, y - z)) / fmaxf(x, y); // Obliczenie wartosci m

	printf("m = %g\n", m); // Print wartosci m


	// DRUGA CZESC (1.2)
	const float e = 2.718281828459; // Definicja wartosci do obliczenia y
	float x2, y2;
	float a = 0.4;
	float b = 2.3;

	printf("Wprowadz x: "); // Zapytania o wprowadzenie wartosci do obliczenia y
	scanf_s("%f", &x2);

	if (x2 < 3.5 * a) { // Warunek 1
		y2 = (a * b * x2) - (pow(cos(x2 * pow(e, 2 * x2)), 2)); // Obliczenie y
		puts("Warunek 1"); // Poinformowanie o spelnionym warunku
		printf("y = %g\n", y2); // Printy y
		printf("y = %0.4e\n", y2);
		printf("Zaokraglenie y = %g\n", round(y2));
	}

	else if (3.5 * a <= x2 && x2 <= b) { // Warunek 2
		y2 = (pow(a - x2, 2)) - (log(pow(e, 2 * x2) + x2));
		puts("Warunek 2");
		printf("y = %g\n", y2);
		printf("y = %0.4e\n", y2);
		printf("Zaokraglenie y = %g\n", round(y2));
	}

	else if (x2 > b) { // Warunek 3
		y2 = sqrt((b * x) - a + (pow(e, 2 * x) * pow(x2, 2)));
		puts("Warunek 3");
		printf("y = %g\n", y2);
		printf("y = %0.4e\n", y2);
		printf("Zaokraglenie y = %g\n", round(y2));
	}

	else { // Opcja gdzie zaden warunek sie nie spelnia
		puts("X nie spelnia zadnego warunku");
	}

	return 0;
}