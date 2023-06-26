#include "psk.h"
#include "utils.h"
#include "includes.h"

/* Modulacja PSK */
void modulatePSK(double *output, int *input, double *time, int fn, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == 0) {
			output[i] = sin(2 * M_PI * fn * time[i]);
		} 
		if (input[(int)time[i]] == 1) {
			output[i] = sin(2 * M_PI * fn * time[i] + M_PI);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("dumps/psk_z.txt", output, N);
		system("python plotting.py psk_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/psk_z.txt", output, N);
		system("python plotting.py psk_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/psk_z.txt", output, N);
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
		printDoubleToFile("dumps/psk_x.txt", x, N);
		printDoubleToFile("dumps/psk_p.txt", p, N);
		printIntToFile("dumps/psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 1 0");
		system("python plotting.py psk_p.txt 1 0");
		system("python plotting.py psk_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/psk_x.txt", x, N);
		printDoubleToFile("dumps/psk_p.txt", p, N);
		printIntToFile("dumps/psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 1 1");
		system("python plotting.py psk_p.txt 1 1");
		system("python plotting.py psk_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/psk_x.txt", x, N);
		printDoubleToFile("dumps/psk_p.txt", p, N);
		printIntToFile("dumps/psk_c.txt", output, N);
		system("python plotting.py psk_x.txt 0 1");
		system("python plotting.py psk_p.txt 0 1");
		system("python plotting.py psk_c.txt 0 1");
	}
}