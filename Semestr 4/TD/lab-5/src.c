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

/* Printowanie tablicy do pliku */
void printDoubleToFile(char *name, double *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%f\n", array[i]);
	}

	fclose(fp);
}

/* Printowanie tablicy do pliku */
void printIntToFile(char *name, int *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d\n", array[i]);
	}

	fclose(fp);
}

/* Skrocenie ciagu do 10 bitow */
void truncate(char *input) {
	int len = strlen(input);
	if (len > 10) {
		input[10] = '\0';
	}
}

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

/* Konwersja sygnalu na bity */
void signalToBinary(int *signal, char *binary, int N, int n) {
	char a;
	int si = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		a = '0';
		if (signal[i] == 1) {
			a = '1';
		}
		if ((int)i/n != si) {
			sprintf(&binary[index], "%c", a);
			index++;
		}
		si = (int)i/n;
	}
	sprintf(&binary[index], "%c", a);
}

/* Konwersja bitow na string */
char* GetSubString(char* str, int index, int count) {
	int strLen = strlen(str);
	int lastIndex = index + count;

	if (index >= 0 && lastIndex > strLen) return "";

	char* subStr = malloc(count + 1);

	for (int i = 0; i < count; i++) {
		subStr[i] = str[index + i];
	}

	subStr[count] = '\0';

	return subStr;
}

char* AppendString(const char* str1, const char* str2) {
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	int strLen = str1Len + str2Len + 1;
	char* str = malloc(strLen);

	for (int i = 0; i < str1Len; i++)
		str[i] = str1[i];

	for (int i = 0; i < str2Len; i++)
		str[(str1Len + i)] = str2[i];

	str[strLen - 1] = '\0';

	return str;
}

char* CharToString(char c) {
	char* str = malloc(2);
	str[0] = c;
	str[1] = '\0';

	return str;
}

int BinaryToDecimal(char* bin)
{
	int binLength = strlen(bin);
	double dec = 0;

	for (int i = 0; i < binLength; ++i)
	{
		dec += (bin[i] - 48) * pow(2, ((binLength - i) - 1));
	}

	return (int)dec;
}

char* BinaryToASCII(char* bin) {
	char* ascii = "";
	int binLen = strlen(bin);

	for (int i = 0; i < binLen; i += 7)
	{
		ascii = AppendString(ascii, CharToString((char)BinaryToDecimal(GetSubString(bin, i, 7))));
	}

	return ascii;
}

/* Obliczenie H */
double calculateH(double *ASKp, int A1, int A2, int N) {
	double H = 0.0;
	double ASKpMax = 0.0;

	for (int i = 0; i < N; i++) {
		if (ASKp[i] > ASKpMax) {
			ASKpMax = ASKp[i];
		}
	}

	H = ASKpMax / fmax(A1, A2) * fmin(A1, A2);

	return H;
}

/* Modulacja ASK */
void modulateASK(double *output, char *input, double *time, int fn, int A1, int A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == '0') {
			output[i] = A1 * sin(2 * M_PI * fn * time[i]);
		} 
		if (input[(int)time[i]] == '1') {
			output[i] = A2 * sin(2 * M_PI * fn * time[i]);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("ask_z.txt", output, N);
		system("plotting.py ask_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("ask_z.txt", output, N);
		system("plotting.py ask_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("ask_z.txt", output, N);
		system("plotting.py ask_z.txt 0 1");
	}
}

/* Demodulacja ASK */
void demodulateASK(int *output, double *input, double *time, int fn, int A1, int A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	double x[N];

	for (int i = 0; i < N; i++) {
		x[i] = input[i] * 2 * sin(2 * M_PI * fn * time[i]);
	}

	double p[N];
	double sum = 0.0;
	int si = 0;

	for (int i = 0; i < N; i++) {
		sum += x[i];
		p[i] = sum;
		if ((int)time[i] != si) {
			sum = 0.0;
		}
		si = (int)time[i];
	}

	double h = calculateH(p, A1, A2, N);

	for (int i = 0; i < N; i++) {
		if (p[i] > h) {
			output[i] = 1;
		} else {
			output[i] = 0;
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("ask_x.txt", x, N);
		printDoubleToFile("ask_p.txt", p, N);
		printIntToFile("ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 1 0");
		system("python plotting.py ask_p.txt 1 0");
		system("python plotting.py ask_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("ask_x.txt", x, N);
		printDoubleToFile("ask_p.txt", p, N);
		printIntToFile("ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 1 1");
		system("python plotting.py ask_p.txt 1 1");
		system("python plotting.py ask_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("ask_x.txt", x, N);
		printDoubleToFile("ask_p.txt", p, N);
		printIntToFile("ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 0 1");
		system("python plotting.py ask_p.txt 0 1");
		system("python plotting.py ask_c.txt 0 1");
	}
}

/* Modulacja PSK */
void modulatePSK(double *output, char *input, double *time, int fn, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == '0') {
			output[i] = sin(2 * M_PI * fn * time[i]);
		} 
		if (input[(int)time[i]] == '1') {
			output[i] = sin(2 * M_PI * fn * time[i] + M_PI);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("psk_z.txt", output, N);
		system("python plotting.py psk_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("psk_z.txt", output, N);
		system("python plotting.py psk_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("psk_z.txt", output, N);
		system("python plotting.py psk_z.txt 0 1");
	}
}

/* Demodulacja PSK */
void demodulatePSK(int *output, double *input, double *time, int fn, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	double x[N];

	for (int i = 0; i < N; i++) {
		x[i] = input[i] * 2 * sin(2 * M_PI * fn * time[i]);
	}

	double p[N];
	double sum = 0.0;
	int si = 0;

	for (int i = 0; i < N; i++) {
		sum += x[i];
		p[i] = sum;
		if ((int)time[i] != si) {
			sum = 0.0;
		}
		si = (int)time[i];
	}

	for (int i = 0; i < N; i++) {
		if (p[i] < 0) {
			output[i] = 1;
		} else {
			output[i] = 0;
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("psk_x.txt", x, N);
		printDoubleToFile("psk_p.txt", p, N);
		printIntToFile("psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 1 0");
		system("python plotting.py psk_p.txt 1 0");
		system("python plotting.py psk_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("psk_x.txt", x, N);
		printDoubleToFile("psk_p.txt", p, N);
		printIntToFile("psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 1 1");
		system("python plotting.py psk_p.txt 1 1");
		system("python plotting.py psk_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("psk_x.txt", x, N);
		printDoubleToFile("psk_p.txt", p, N);
		printIntToFile("psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 0 1");
		system("python plotting.py psk_p.txt 0 1");
		system("python plotting.py psk_c.txt 0 1");
	}
}

/* Modulacja FSK */
void modulateFSK(double *output, char *input, double *time, int f1, int f2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == '0') {
			output[i] = sin(2 * M_PI * f1 * time[i]);
		} 
		if (input[(int)time[i]] == '1') {
			output[i] = sin(2 * M_PI * f2 * time[i]);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("fsk_z.txt", output, N);
		system("python plotting.py fsk_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("fsk_z.txt", output, N);
		system("python plotting.py fsk_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("fsk_z.txt", output, N);
		system("python plotting.py fsk_z.txt 0 1");
	}
}

/* Demodulacja FSK */
void demodulateFSK(int *output, double *input, double *time, int f1, int f2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	double x1[N];
	double x2[N];

	for (int i = 0; i < N; i++) {
		x1[i] = input[i] * 2 * sin(2 * M_PI * f1 * time[i]);
		x2[i] = input[i] * 2 * sin(2 * M_PI * f2 * time[i]);
	}

	double p1[N];
	double p2[N];
	double sum1 = 0.0;
	double sum2 = 0.0;
	int si1 = 0;
	int si2 = 0;

	for (int i = 0; i < N; i++) {
		sum1 += x1[i];
		sum2 += x2[i];
		p1[i] = sum1;
		p2[i] = sum2;
		if ((int)time[i] != si1) {
			sum1 = 0.0;
		}
		if ((int)time[i] != si2) {
			sum2 = 0.0;
		}
		si1 = (int)time[i];
		si2 = (int)time[i];
	}


	for (int i = 0; i < N; i++) {
		if (-p1[i] + p2[i] > 0) {
			output[i] = 1;
		} else {
			output[i] = 0;
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("fsk_x1.txt", x1, N);
		printDoubleToFile("fsk_x2.txt", x2, N);
		printDoubleToFile("fsk_p1.txt", p1, N);
		printDoubleToFile("fsk_p2.txt", p2, N);
		printIntToFile("fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 1 0");
		system("python plotting.py fsk_x2.txt 1 0");
		system("python plotting.py fsk_p1.txt 1 0");
		system("python plotting.py fsk_p2.txt 1 0");
		system("python plotting.py fsk_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("fsk_x1.txt", x1, N);
		printDoubleToFile("fsk_x2.txt", x2, N);
		printDoubleToFile("fsk_p1.txt", p1, N);
		printDoubleToFile("fsk_p2.txt", p2, N);
		printIntToFile("fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 1 1");
		system("python plotting.py fsk_x2.txt 1 1");
		system("python plotting.py fsk_p1.txt 1 1");
		system("python plotting.py fsk_p2.txt 1 1");
		system("python plotting.py fsk_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("fsk_x1.txt", x1, N);
		printDoubleToFile("fsk_x2.txt", x2, N);
		printDoubleToFile("fsk_p1.txt", p1, N);
		printDoubleToFile("fsk_p2.txt", p2, N);
		printIntToFile("fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 0 1");
		system("python plotting.py fsk_x2.txt 0 1");
		system("python plotting.py fsk_p1.txt 0 1");
		system("python plotting.py fsk_p2.txt 0 1");
		system("python plotting.py fsk_c.txt 0 1");
	}
}

int main() {
	char *message = stringToBinary("Dupa Pawiana");
	truncate(message);
	int sLen = strlen(message);

	int tb = 1;
	int tc = tb * sLen;
	int W = 2;
	double fn = W / tb;
	int fs = 200;
	int n = tb * fs;
	int N = tc * fs;
	int A1 = 2;
	int A2 = 20;
	int fn1 = 1;
	int fn2 = 10;

	double time[N];
	generateTime(time, fs, N);
	printDoubleToFile("time.txt", time, N);
	
	// ASK
	double modulatedASK[N];
	modulateASK(modulatedASK, message, time, fn, A1, A2, N, 0, 1);
	int demodulatedASK[N];
	demodulateASK(demodulatedASK, modulatedASK, time, fn, A1, A2, N, 0, 1);
	char decodedASK[sLen];
	signalToBinary(demodulatedASK, decodedASK, N, n);

	printf("ASK:\nWyslane:  %s Tekst: %s\nOdebrane: %s Tekst: %s\n\n", message, BinaryToASCII(message), decodedASK, BinaryToASCII(decodedASK));
	
	// PSK
	double modulatedPSK[N];
	modulatePSK(modulatedPSK, message, time, fn, N, 0, 1);
	int demodulatedPSK[N];
	demodulatePSK(demodulatedPSK, modulatedPSK, time, fn, N, 0, 1);
	char decodedPSK[sLen];
	signalToBinary(demodulatedPSK, decodedPSK, N, n);

	printf("PSK:\nWyslane:  %s Tekst: %s\nOdebrane: %s Tekst: %s\n\n", message, BinaryToASCII(message), decodedPSK, BinaryToASCII(decodedPSK));
	
	// FSK
	double modulatedFSK[N];
	modulateFSK(modulatedFSK, message, time, fn1, fn2, N, 0, 1);
	int demodulatedFSK[N];
	demodulateFSK(demodulatedFSK, modulatedFSK, time, fn1, fn2, N, 0, 1);
	char decodedFSK[sLen];
	signalToBinary(demodulatedFSK, decodedFSK, N, n);

	printf("FSK:\nWyslane:  %s Tekst: %s\nOdebrane: %s Tekst: %s\n\n", message, BinaryToASCII(message), decodedFSK, BinaryToASCII(decodedFSK));

	free(message);
}