#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main()
{
	float x, a, f, f1, f2, f3;

	printf("Wprowadz x: "); // Zapytania o, i inputy wartosci x oraz a
	scanf_s("%f", &x);
	printf("Wprowadz a: ");
	scanf_s("%f", &a);

	f1 = pow(cos(a), 2); // Obliczanie krokowe f
	f2 = pow(pow(x, 2) * sqrt(fabs(a + x)), 2);
	f3 = pow(sin(pow(x, 2) * sqrt(fabs(a + x))), 2);

	f = (a * pow(f1 + f2, 7)) + f3; // Obliczanie koncowej wartosci f
	printf("f = %0.4e\n", f); // Print wartosci f

	return 0;
}