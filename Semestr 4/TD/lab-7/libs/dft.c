#include "dft.h"
#include "includes.h"

/* Obliczanie DFT */
void dft(struct complexnum *cplx, double *input, int N) {
	for (int k = 0; k < N; k++) {
		cplx[k].re = 0;
		cplx[k].im = 0;
		for (int n = 0; n < N; n++) {
			cplx[k].re += input[n] * cos((2 * M_PI * k * n) / N);
			cplx[k].im += input[n] * sin((2 * M_PI * k * n) / N);
		}
	}
}

/* Obliczanie spektrum amplitudowego */
void amplitudeSpectrum(struct complexnum *cplx, double *AS, int N) {
	for (int k = 0; k < N / 2 - 1; k++) {
		AS[k] = sqrt(pow(cplx[k].re, 2) + pow(cplx[k].im, 2));
	}
}

/* Obliczanie spektrum amplitudowego w skali decybelowej */
void amplitudeSpectrumDb(double *AS, double *ASdb, int N) {
	for (int k = 0; k < N / 2 - 1; k++) {
		ASdb[k] = 10 * log10(AS[k]);
	}
}