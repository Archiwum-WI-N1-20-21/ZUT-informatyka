#include "ask.h"
#include "utils.h"
#include "includes.h"

/* Obliczenie H */
double calculateH(double *ASKp, double A1, double A2, int N) {
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
void modulateASK(double *output, int *input, double *time, int fn, double A1, double A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == 0) {
			output[i] = A1 * sin(2 * M_PI * fn * time[i]);
		} 
		if (input[(int)time[i]] == 1) {
			output[i] = A2 * sin(2 * M_PI * fn * time[i]);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("dumps/ask_z.txt", output, N);
		system("plotting.py ask_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/ask_z.txt", output, N);
		system("plotting.py ask_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/ask_z.txt", output, N);
		system("plotting.py ask_z.txt 0 1");
	}
}

/* Demodulacja ASK */
void demodulateASK(int *output, double *input, double *time, int fn, double A1, double A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
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
		printDoubleToFile("dumps/ask_x.txt", x, N);
		printDoubleToFile("dumps/ask_p.txt", p, N);
		printIntToFile("dumps/ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 1 0");
		system("python plotting.py ask_p.txt 1 0");
		system("python plotting.py ask_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/ask_x.txt", x, N);
		printDoubleToFile("dumps/ask_p.txt", p, N);
		printIntToFile("dumps/ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 1 1");
		system("python plotting.py ask_p.txt 1 1");
		system("python plotting.py ask_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/ask_x.txt", x, N);
		printDoubleToFile("dumps/ask_p.txt", p, N);
		printIntToFile("dumps/ask_c.txt", output, N);
		system("python plotting.py ask_x.txt 0 1");
		system("python plotting.py ask_p.txt 0 1");
		system("python plotting.py ask_c.txt 0 1");
	}
}