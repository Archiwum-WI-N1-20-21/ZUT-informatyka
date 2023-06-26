#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	// tabela 3 - funkcja 3
	FILE *fptr_fu, *fptr_t;

	int f = 20;
	int fs = 8000;
	int fi = 2;
	int tc = 4;
	int N = fs * tc;
	double fu[N];
	double t[N];
	int ti;

	for (int i = 0; i < N; i++) {
		t[i] = (double)i / fs;
		if (t[i] >= 0.0 && t[i] < 1.2) {
			fu[i] = (pow((t[i] * -1), 2) + 0.5) * sin(30 * M_PI * t[i]) * log2(pow(t[i], 2) + 1);
		}
		else if (t[i] >= 1.2 && t[i] < 2.0) {
			fu[i] = (1/t[i]) * 0.8 * sin(24 * M_PI * t[i]) - 0.1 * t[i];
		}
		else if (t[i] >= 2.0 && t[i] < 2.4) {
			fu[i] = pow(abs(sin(2 * M_PI * pow(t[i], 2))), 0.8);
		}
		else if (t[i] >= 2.4 && t[i] < 3.1) {
			fu[i] = 0.23 * sin(20 * M_PI * t[i]) * sin(12 * M_PI * t[i]);
		}
		else if (t[i] >= 3.1) {
			ti = i;
			break;
		}
	}

	fptr_fu = fopen("dump1fu.txt", "w");
	fptr_t = fopen("dump1t.txt", "w");

	for (int i = 0; i < ti; i++) {
		fprintf(fptr_fu, "%f\n", fu[i]);
		fprintf(fptr_t, "%f\n", t[i]);
	}

	fclose(fptr_fu);
	fclose(fptr_t);

	return 0;
}