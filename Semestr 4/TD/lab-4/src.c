#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

/* Struktura do obslugi liczb zespolonych */
struct complexnum {
	double re;
	double im;
};

/* Generowanie tablicy czasu */
void generateTime(double *time, int fs, int N) {
	for (int i = 0; i < N; i++) {
		time[i] = (double)i / fs;
	}
}

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

/* Konwersja stringa na bity */
char* stringToBinary(char* input) {
    if (input == NULL) return 0;
    int len = strlen(input);
    char *binary = malloc(len * 7);
    binary[0] = '\0';
    for(int i = 0; i < len; ++i) {
        char ch = input[i];
        for(int j = 6; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

/* ASK */
void amplitudeShift(double *output, char *input, double *time, int fn, int A1, int A2, int sLen, int N) {
	int k = 0; // indexer bitow
	int p = 1; // potega po dzieleniu
	int z = N / sLen; // podstawa

	for (int i = 0; i < N; i++) {
		if (input[k] == '0') {
			output[i] = A1 * sin(2 * M_PI * fn * time[i]);
		}
		if (input[k] == '1') {
			output[i] = A2 * sin(2 * M_PI * fn * time[i]);
		}
		if (i >= z * p) {
			k++;
			p++;
		}
	}
}

/* PSK */
void phaseShift(double *output, char *input, double *time, int f, int sLen, int N) {
	int k = 0; // indexer bitow
	int p = 1; // potega po dzieleniu
	int z = N / sLen; // podstawa

	for (int i = 0; i < N; i++) {
		if (input[k] == '0') {
			output[i] = sin(2 * M_PI * f * time[i]);
		}
		if (input[k] == '1') {
			output[i] = sin(2 * M_PI * f * time[i] + M_PI);
		}
		if (i >= z * p) {
			k++;
			p++;
		}
	}
}

/* FSK */
void frequencyShift(double *output, char *input, double *time, int f1, int f2, int sLen, int N) { // FIXME fsk
	int k = 0; // indexer bitow
	int p = 1; // potega po dzieleniu
	int z = N / sLen; // podstawa

	for (int i = 0; i < N; i++) {
		if (input[k] == '0') {
			output[i] = sin(2 * M_PI * f1 * time[i]);
		}
		if (input[k] == '1') {
			output[i] = sin(2 * M_PI * f2 * time[i]);
		}
		if (i >= z * p) {
			k++;
			p++;
		}
	}
}

/* Skrocenie ciagu do 10 bitow */
void truncate(char *input, int N) {
	int len = strlen(input);
	if (len > 10) {
		input[10] = '\0';
	}
}

/* Printowanie tablicy do pliku */
void printToFile(char *name, double *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%f\n", array[i]);
	}

	fclose(fp);
}

int main() {
	int tc = 1;
	int W = 2;
	int B = 10;
	double tb = tc / B;
	int A1 = 3;
	int A2 = 7;
	int fn = W * B;
	double fn1 = (W + 1) / tb;
	double fn2 = (W + 2) / tb;
	double fs = 500;
	int N = tc * fs;

	double time[N];
	double ask[N];
	double ask_db[N / 2 - 1];
	double psk[N];
	double psk_db[N / 2 - 1];
	double fsk[N];
	double fsk_db[N / 2 - 1];

	struct complexnum cplx[N];
	double temp[N];

	generateTime(time, fs, N);

	char *message = stringToBinary("Marcel");

	truncate(message, 10);

	amplitudeShift(ask, message, time, fn, A1, A2, strlen(message), N);
	dft(cplx, ask, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, ask_db, N);

	phaseShift(psk, message, time, fn, strlen(message), N);
	dft(cplx, psk, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, psk_db, N);
	
	frequencyShift(fsk, message, time, fn1, fn2, strlen(message), N);
	dft(cplx, fsk, N);
	amplitudeSpectrum(cplx, temp, N);
	amplitudeSpectrumDb(temp, fsk_db, N);

	printToFile("ask.txt", ask, N);
	printToFile("ask_db.txt", ask_db, N / 2 - 1);
	printToFile("psk.txt", psk, N);
	printToFile("psk_db.txt", psk_db, N / 2 - 1);
	printToFile("fsk.txt", fsk, N);
	printToFile("fsk_db.txt", fsk_db, N / 2 - 1);
	printToFile("time.txt", time, N);

	free(message);

	return 0;
}