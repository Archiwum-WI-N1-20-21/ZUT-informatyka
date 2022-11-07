#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <math.h>
#include <time.h>

HANDLE ghMutex;
double leibnzSumTh = 1.0;

typedef struct leibnzData {
	unsigned int start;
	unsigned int stop;
} leibnzData;

void calculate(void* arg) {
	double ret = 1.0;
	int tid = _getpid();

	printf("Pid: %d, Size: %d, Start: %d\n", tid, ((leibnzData*)arg)->stop - ((leibnzData*)arg)->start + 1, ((leibnzData*)arg)->start);

	for (int n = ((leibnzData*)arg)->start; n <= ((leibnzData*)arg)->stop; n++) {
		double x = (double)n;
		ret += pow(-1, x) / ((2 * x) + 1);
	}
	printf("Pid: %d, Sum=%.20f\n", tid, ret);

	WaitForSingleObject(ghMutex, INFINITE);
	leibnzSumTh *= ret;
	ReleaseMutex(ghMutex);
}

int main(int args, char* argv[]) {
	if (args != 3) {
	fprintf(stderr, "%s", "Args amount different than 2\n");
	return 1;
	}

	char* tmpptr;
	unsigned int n = strtol(argv[1], &tmpptr, 10);
	unsigned int w = strtol(argv[2], &tmpptr, 10);

	if (n < 1 || n > 1000000000 || w < 1 || w > 100) {
		fprintf(stderr, "%s", "Args values are incorrect, amount to calculate must be in range 1-1000000000, amount of threads 1-100\n");
	}

	srand(time(0));
	clock_t begin, end;
	double totalTime, totalTimeTh;

	leibnzData* leibnzArray = malloc(sizeof(*leibnzArray) * w);
	if (leibnzArray == NULL) {
		printf("Memory allocation error\n");
		return 1;
	}
	else {
		printf("Memory allocation successful\n");
	}

	if (n % w == 0) {
		for (int i = 1; i <= w; i++) {
			leibnzArray[i].start = ((n / w) * i) - ((n / w) - 1);
			leibnzArray[i].stop = (n / w) * i;
		}
	}
	else {
		for (int i = 1; i <= w; i++) {
		leibnzArray[i].start = ((n / w) * i) - ((n / w) - 1);
		leibnzArray[i].stop = (n / w) * i;
		if (i == w) {
			leibnzArray[i].start = ((n / w) * i) - ((n / w) - 1);
			leibnzArray[i].stop = (n / w) * i + 1;
		}
		}
	}

	HANDLE* hs = malloc(w * sizeof(HANDLE));

	ghMutex = CreateMutex(NULL, FALSE, NULL);

	begin = clock();

	for (int i = 1; i <= w; i++) {
		hs[i] = CreateThread(NULL, 0, calculate, &leibnzArray[i], 0, NULL);
	}

	WaitForMultipleObjects(w, hs, TRUE, INFINITE);

	end = clock();
	totalTimeTh = (double)(end - begin) / CLOCKS_PER_SEC;

	begin = clock();
	double leibnzSum = 1.0;
	for (double i = 1; i <= n; i++) {
		leibnzSum += pow(-1, i) / ((2 * i) + 1);
	}

	end = clock();
	totalTime = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nw/Threads: PI=%.20f, Time: %0.3f\n", leibnzSumTh * 4, totalTimeTh);
	printf("wo/Threads: PI=%.20f, Time: %0.3f\n\n", leibnzSum * 4, totalTime);

	free(leibnzArray);
	free(hs);
	return 0;
}