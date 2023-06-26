#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	// tabela 4 - funkcja 14
	FILE *fptr_b1, *fptr_b2, *fptr_b3, *fptr_t1, *fptr_t2, *fptr_t3;

	int f = 22050;
	int fs = 8000;
	int fi = 2;
	int tc = 1;
	int N = fs * tc;
	double sumLimit[3] = {2.0, 6.0, 10.0};
	double sum[3] = {0.0, 0.0, 0.0};
	double b1[N], b2[N], b3[N];
	double t1[N], t2[N], t3[N];
	double *b[3] = {b1, b2, b3};
	double *time[3] = {t1, t2, t3};
    int th[3];

	for (int i = 0; i < 3; i++) {
		for (int h = 1; ; h++) {
			if (sum[i] <= sumLimit[i]) {
				time[i][h] = (double)h / fs;
				b[i][h] = (sin((h * time[i][h] * M_PI) / 2) / (2 + cos(pow(h, 2) * M_PI * time[i][h])));
				sum[i] += b[i][h];
                th[i] = h;
			}
			else {
				break;
			}
		}
	}

	fptr_b1 = fopen("dump1b1.txt", "w");
	fptr_b2 = fopen("dump1b2.txt", "w");
	fptr_b3 = fopen("dump1b3.txt", "w");
	fptr_t1 = fopen("dump1t1.txt", "w");
	fptr_t2 = fopen("dump1t2.txt", "w");
	fptr_t3 = fopen("dump1t3.txt", "w");

	for (int i = 0; i < th[0]; i++) {
		fprintf(fptr_b1, "%f\n", b1[i]);
		fprintf(fptr_t1, "%f\n", time[0][i]);
	}

    for (int i = 0; i < th[1]; i++) {
		fprintf(fptr_b2, "%f\n", b2[i]);
		fprintf(fptr_t2, "%f\n", time[1][i]);
	}

    for (int i = 0; i < th[2]; i++) {
		fprintf(fptr_b3, "%f\n", b3[i]);
		fprintf(fptr_t3, "%f\n", time[2][i]);
	}

	fclose(fptr_b1);
	fclose(fptr_b2);
	fclose(fptr_b3);
	fclose(fptr_t1);
	fclose(fptr_t2);
	fclose(fptr_t3);

	return 0;
}