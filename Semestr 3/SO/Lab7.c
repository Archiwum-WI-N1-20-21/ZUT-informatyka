#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
double wallisSumTh = 1.0;

typedef struct wallisData {
	unsigned int start;
	unsigned int stop;
} wallisData;

void *calculate(void *arg) {
	double ret = 1.0;
	pid_t tid = getpid();

	printf("Pid: %u, Size: %d, Start: %d\n", tid, ((wallisData*)arg)->stop - ((wallisData*)arg)->start + 1, ((wallisData*)arg)->start);

	for (int n = ((wallisData*)arg)->start; n <= ((wallisData*)arg)->stop; n++) {
		double x = (double)n;
		ret *= ((2 * x) * (2 * x)) / ((2 * x - 1) * (2 * x + 1));
	}
	printf("Pid: %u, Sum=%.20f\n", tid, ret);

	pthread_mutex_lock(&mutex);
	wallisSumTh *= ret;
	pthread_mutex_unlock(&mutex);
}

int main(int args, char *argv[]) {
	if (args != 3) {
		fprintf(stderr, "%s", "Args amount different than 2\n");
		return 1;
	}

	char *tmpptr;
	unsigned int n = strtol(argv[1], &tmpptr, 10);
	unsigned int w = strtol(argv[2], &tmpptr, 10);

	if (n < 1 || n > 1000000000 || w < 1 || w > 100) {
		fprintf(stderr, "%s", "Args values are incorrect, amount to calculate must be in range 1-1000000000, amount of threads 1-100\n");
	}

	srand(time(0));
	clock_t begin, end;
	double totalTime, totalTimeTh;

	wallisData *wallisArray = malloc(sizeof(*wallisArray) * w);
	if (wallisArray == NULL) {
		printf("Memory allocation error\n");
		return 1;
	}
	else {
		printf("Memory allocation successful\n"); // this exists only because malloc fails for some strange reason
	}

	if (n % w == 0) {
		for (int i = 1; i <= w; i++) {
			wallisArray[i].start = ((n / w) * i) - ((n / w) - 1); 
			wallisArray[i].stop = (n / w) * i;
		}
	} 
	else {
		for (int i = 1; i <= w; i++) {
			wallisArray[i].start = ((n / w) * i) - ((n / w) - 1); 
			wallisArray[i].stop = (n / w) * i;
			if (i == w) {
				wallisArray[i].start = ((n / w) * i) - ((n / w) - 1);
				wallisArray[i].stop = (n / w) * i + 1;
			}
		}
	}

	/*
	// DEBUG
	for (int i = 1; i <= w; i++) {
		printf("DEBUG: Start: %d, Stop: %d\n", wallisArray[i].start, wallisArray[i].stop);
	}
	*/

	begin = clock();

	pthread_t threads[w];
	for (int i = 1; i <= w; i++) {
		pthread_create(&threads[i], NULL, calculate, &wallisArray[i]);
	}

	for (int i = 1; i <= w; i++) {
		pthread_join(threads[i], NULL);
	}

	end = clock();
	totalTimeTh = (double)(end - begin) / CLOCKS_PER_SEC;

	begin = clock();

	double wallisSum = 1;
	for (double i = 1; i <= n; i++) {
		wallisSum *= ((2 * i) * (2 * i)) / ((2 * i - 1) * (2 * i + 1));
	}

	end = clock();
	totalTime = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nw/Threads: PI=%.20f, Time: %0.3f\n", wallisSumTh * 2, totalTimeTh);
	printf("wo/Threads: PI=%.20f, Time: %0.3f\n\n", wallisSum * 2, totalTime);
	
	free(wallisArray);
	
	return 0;
}