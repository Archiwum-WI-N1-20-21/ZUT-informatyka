#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

struct complexnum{
	double re;
	double im;
};

void generateTime(double *time, int fs, int N) {
	for (int i = 0; i < N; i++) {
		time[i] = (double)i / fs;
	}
}

void generateSinusoid(double *sinusoid, double *t, int f, int N) {
	for (int i = 0; i < N; i++) {
		sinusoid[i] = sin(2 * M_PI * f * t[i]);
	}
}

void dft(struct complexnum *cplx, double *input, int N) {
	for (int k = 0; k < N; k++) {
		cplx[k].re = 0;
		cplx[k].im = 0;
		for (int n = 0; n < N; n++) {
			cplx[k].re += input[n] * cos((2 * 3.141592 * k * n) / N);
			cplx[k].im += input[n] * sin((2 * 3.141592 * k * n) / N);
		}
	}
}

void amplitudeSpectrum(struct complexnum *cplx, double *AS, int N) {
	for (int k = 0; k < N / 2 - 1; k++) {
		AS[k] = sqrt(pow(cplx[k].re, 2) + pow(cplx[k].im, 2));
	}
}

void amplitudeSpectrumDb(double *AS, double *ASdb, int N) {
	for (int k = 0; k < N / 2 - 1; k++) {
		ASdb[k] = 10 * log10(AS[k]);
	}
}

void printToFile(char *name, double *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%f\n", array[i]);
	}

	fclose(fp);
}

void printCplxToFile(char *name1, char *name2 ,struct complexnum *array, int N) {
	FILE *fp1, *fp2;

	fp1 = fopen(name1, "w");
	fp2 = fopen(name2, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp1, "%f\n", array[i].re);
		fprintf(fp2, "%f\n", array[i].im);
	}

	fclose(fp1);
	fclose(fp2);
}

int main() {
	int f = 24;
	int fs = 256;
	int tc = 1;
	int N = fs * tc;
	double sinusoid[N];
	struct complexnum cplx[N];
	double AS[N / 2 - 1];
	double ASdb[N / 2 - 1];
	double sum = 0;
	double t[N];

	generateTime(t, fs, N);
	generateSinusoid(sinusoid, t, f, N); 
	
	dft(cplx, sinusoid, N);
	amplitudeSpectrum(cplx, AS, N / 2 - 1);
	amplitudeSpectrumDb(AS, ASdb, N / 2 - 1);

	double freqScale = ((double)N / 2) * ((double)fs / (double)N);
	printf("Frequency scale: %f", freqScale);  

	printToFile("sinus.txt", sinusoid, N);
	printToFile("t.txt", t, N);
	printToFile("AS.txt", AS, N / 2 - 1);
	printToFile("ASdb.txt", ASdb, N / 2 - 1);

	return 0;
} 