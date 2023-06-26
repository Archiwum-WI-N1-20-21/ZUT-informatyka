#include "fsk.h"
#include "utils.h"
#include "includes.h"

/* Modulacja FSK */
void modulateFSK(double *output, int *input, double *time, int f1, int f2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		if (input[(int)time[i]] == 0) {
			output[i] = sin(2 * M_PI * f1 * time[i]);
		} 
		if (input[(int)time[i]] == 1) {
			output[i] = sin(2 * M_PI * f2 * time[i]);
		}
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
		printDoubleToFile("dumps/fsk_z.txt", output, N);
		system("python plotting.py fsk_z.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/fsk_z.txt", output, N);
		system("python plotting.py fsk_z.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/fsk_z.txt", output, N);
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
		printDoubleToFile("dumps/fsk_x1.txt", x1, N);
		printDoubleToFile("dumps/fsk_x2.txt", x2, N);
		printDoubleToFile("dumps/fsk_p1.txt", p1, N);
		printDoubleToFile("dumps/fsk_p2.txt", p2, N);
		printIntToFile("dumps/fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 1 0");
		system("python plotting.py fsk_x2.txt 1 0");
		system("python plotting.py fsk_p1.txt 1 0");
		system("python plotting.py fsk_p2.txt 1 0");
		system("python plotting.py fsk_c.txt 1 0");
	}

	if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/fsk_x1.txt", x1, N);
		printDoubleToFile("dumps/fsk_x2.txt", x2, N);
		printDoubleToFile("dumps/fsk_p1.txt", p1, N);
		printDoubleToFile("dumps/fsk_p2.txt", p2, N);
		printIntToFile("dumps/fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 1 1");
		system("python plotting.py fsk_x2.txt 1 1");
		system("python plotting.py fsk_p1.txt 1 1");
		system("python plotting.py fsk_p2.txt 1 1");
		system("python plotting.py fsk_c.txt 1 1");
	}

	if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
		printDoubleToFile("dumps/fsk_x1.txt", x1, N);
		printDoubleToFile("dumps/fsk_x2.txt", x2, N);
		printDoubleToFile("dumps/fsk_p1.txt", p1, N);
		printDoubleToFile("dumps/fsk_p2.txt", p2, N);
		printIntToFile("dumps/fsk_c.txt", output, N);
		system("python plotting.py fsk_x1.txt 0 1");
		system("python plotting.py fsk_x2.txt 0 1");
		system("python plotting.py fsk_p1.txt 0 1");
		system("python plotting.py fsk_p2.txt 0 1");
		system("python plotting.py fsk_c.txt 0 1");
	}
}