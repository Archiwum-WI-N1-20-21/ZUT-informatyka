#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	// tabela 2 - funkcja 4
	FILE *fptr_fy, *fptr_fz, *fptr_fv, *fptr_t;

	int f = 20;
	int fs = 8000;
	int fi = 2;
	int tc = 2;
	int N = fs * tc;
	double fx[N];
	double fy[N];
	double fz[N];
	double fv[N];
	double t[N];

	for (int i = 0; i < N; i++) {
		t[i] = (double)i / fs;
		fx[i] = sin(2 * M_PI * f * t[i] * cos(3 * M_PI * t[i]) + t[i] * fi);
		fy[i] = pow((t[i] * -1), 2) * cos(t[i] / 0.2) * fx[i];
		fz[i] = fx[i] * cos(2 * M_PI * pow(t[i], 2) + M_PI) + 0.276 * pow(t[i], 2) * fx[i];
		fv[i] = sqrt(abs(1.77 - fy[i] + fz[i]) * cos(5.2 * M_PI * t[i]) + fx[i] + 4);
	}

	fptr_fy = fopen("dump1fy.txt", "w");
	fptr_fz = fopen("dump1fz.txt", "w");
	fptr_fv = fopen("dump1fv.txt", "w");
	fptr_t = fopen("dump1t.txt", "w");

	for (int i = 0; i < N; i++) {
		fprintf(fptr_fy, "%f\n", fy[i]);
		fprintf(fptr_fz, "%f\n", fz[i]);
		fprintf(fptr_fv, "%f\n", fv[i]);
		fprintf(fptr_t, "%f\n", t[i]);
	}

	fclose(fptr_fy);
	fclose(fptr_fz);
	fclose(fptr_fv);
	fclose(fptr_t);

	return 0;
}