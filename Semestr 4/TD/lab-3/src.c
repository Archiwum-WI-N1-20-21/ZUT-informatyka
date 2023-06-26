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
			cplx[k].re += input[n] * cos((2 * M_PI * k * n) / N);
			cplx[k].im += input[n] * sin((2 * M_PI * k * n) / N);
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

void amplitudeModulation(double *output, double *input, double *time, int f, int modifier, int N) {
	for (int i = 0; i < N; i++) {
		output[i] = (modifier * input[i] + 1) * cos(2 * M_PI * f * time[i]);
	}
}

void phaseModulation(double *output, double *input, double *time, int f, int modifier, int N) {
	for (int i = 0; i < N; i++) {
		output[i] = cos(2 * M_PI * f * time[i] + modifier * input[i]);
	}
}

void frequencyModulation(double *output, double *input, double *time, int f, int fm, int modifier, int N) {
	for (int i = 0; i < N; i++) {
		output[i] = cos(2 * M_PI * f * time[i] + (modifier / fm) * input[i]);
	}
}

int main() {
	int fn = 50;// f nosna
	int fm = 1; // f informacyjna 
	int fs = 400; // f probkowania
	int tc = 1; // czas calkowity
	int N = fs * tc; // ilosc probek

	// sinusoida
	double sinus[N];

	// modulacja amplitudy
	double ma_a[N];
	double w_ma_a[N / 2 - 1];
	double ma_b[N / 2 - 1];
	double w_ma_b[N / 2 - 1];
	double ma_c[N];
	double w_ma_c[N / 2 - 1];
	
	// modulacja fazy
	double pm_a[N];
	double w_pm_a[N / 2 - 1];
	double pm_b[N];
	double w_pm_b[N / 2 - 1];
	double pm_c[N];
	double w_pm_c[N / 2 - 1];

	// modulacja czestotliwosci
	double fm_a[N];
	double w_fm_a[N / 2 - 1];
	double fm_b[N];
	double w_fm_b[N / 2 - 1];
	double fm_c[N];
	double w_fm_c[N / 2 - 1];

	// czas
	double t[N];

	struct complexnum cplx[N];
	double temp[N / 2 - 1];

	generateTime(t, fs, N);
	generateSinusoid(sinus, t, fm, N);

	printToFile("t.txt", t, N);
	printToFile("sinus.txt", sinus, N);

	amplitudeModulation(ma_a, sinus, t, fn, 0.64, N);
	dft(cplx, ma_a, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_ma_a, N);
	printToFile("ma_a.txt", ma_a, N);
	printToFile("w_ma_a.txt", w_ma_a, N / 2 - 1);

	amplitudeModulation(ma_b, sinus, t, fn, 7.0, N);
	dft(cplx, ma_b, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_ma_b, N);
	printToFile("ma_b.txt", ma_b, N);
	printToFile("w_ma_b.txt", w_ma_b, N / 2 - 1);

	amplitudeModulation(ma_c, sinus, t, fn, 24.0, N);
	dft(cplx, ma_c, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_ma_c, N);
	printToFile("ma_c.txt", ma_c, N);
	printToFile("w_ma_c.txt", w_ma_c, N / 2 - 1);

	phaseModulation(pm_a, sinus, t, fn, 0.24, N);
	dft(cplx, pm_a, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_pm_a, N);
	printToFile("pm_a.txt", pm_a, N);
	printToFile("w_pm_a.txt", w_pm_a, N / 2 - 1);

	phaseModulation(pm_b, sinus, t, fn, 1.25, N);
	dft(cplx, pm_b, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_pm_b, N);
	printToFile("pm_b.txt", pm_b, N);
	printToFile("w_pm_b.txt", w_pm_b, N / 2 - 1);

	phaseModulation(pm_c, sinus, t, fn, 16.0, N);
	dft(cplx, pm_c, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_pm_c, N);
	printToFile("pm_c.txt", pm_c, N);
	printToFile("w_pm_c.txt", w_pm_c, N / 2 - 1);

	frequencyModulation(fm_a, sinus, t, fn, fm, 0.21, N);
	dft(cplx, fm_a, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_fm_a, N);
	printToFile("fm_a.txt", fm_a, N);
	printToFile("w_fm_a.txt", w_fm_a, N / 2 - 1);

	frequencyModulation(fm_b, sinus, t, fn, fm, 1.64, N);
	dft(cplx, fm_b, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_fm_b, N);
	printToFile("fm_b.txt", fm_b, N);
	printToFile("w_fm_b.txt", w_fm_b, N / 2 - 1);

	frequencyModulation(fm_c, sinus, t, fn, fm, 32.0, N);
	dft(cplx, fm_c, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, w_fm_c, N);
	printToFile("fm_c.txt", fm_c, N);
	printToFile("w_fm_c.txt", w_fm_c, N / 2 - 1);

	return 0;
}