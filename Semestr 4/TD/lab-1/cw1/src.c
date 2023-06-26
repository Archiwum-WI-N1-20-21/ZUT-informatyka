#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	// tabela 1 - funkcja 5
	FILE *fptr_f, *fptr_t;

	int f = 20;
	int fs = 8000;
	int fi = 2;
	int tc = 2;
	int N = fs * tc;
	double fx[N];
	double t[N];

	for (int i = 0; i < N; i++) {
		t[i] = (double)i / fs;
		fx[i] = sin(2 * M_PI * f * t[i] * cos(3 * M_PI * t[i]) + t[i] * fi);
	}

	fptr_f = fopen("dump1f.txt", "w");
	fptr_t = fopen("dump1t.txt", "w");

	for (int i = 0; i < N; i++) {
		fprintf(fptr_f, "%f\n", fx[i]);
		fprintf(fptr_t, "%f\n", t[i]);
	}

	fclose(fptr_f);
	fclose(fptr_t);

	return 0;
}