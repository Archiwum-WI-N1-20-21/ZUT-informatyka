#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct array {
	int integer;
	char character;
	float floating;
};


struct array** draw(int N) {
	struct array **ar = (struct array**) malloc(N * sizeof(struct array*));

	for (int i = 0; i < N; i++) {
		ar[i] = (struct array*) malloc(sizeof(struct array));
	}

	for (int i = 0; i < N; i++) {
		ar[i]->integer = -1000 + (rand() % (9000 - (-1000) + 1)); // range -1000 to 9000
		ar[i]->character = (rand() % 18) + 66; // range B to S
		ar[i]->floating = 1000 + i + 1;
	}

	return ar;
}

void rem(struct array **ar, int N) {
	for (int i = 0; i < N; i++) {
		free(ar[i]);
	}
	free(ar);
}

void sort(struct array **ar, int N) {
	struct array *tempar;
	int counter = 0;
	bool swapped = false;

	for (int i = 0; i < N - 1; i++) {
		swapped = false;
		for (int j = 0; j < N - i - 1; j++) {
			if (ar[j]->integer > ar[j + 1]->integer) {
				tempar = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tempar;
				swapped = true;
			}
			counter += 1;
		}
		counter += 1;
		if (!swapped) break;
	}
}

int count(struct array **ar, int N, unsigned char X) {
	int counter = 0;

	for (int i = 0; i < N; i++) {
		if (ar[i]->character == X) {
			counter += 1;
		}
	}

	return counter;
}

int main()
{
	srand(time(0));

	clock_t begin, end;
	double time_spent;

	int N;
	unsigned char X;
	FILE* fp = fopen("inlab01.txt", "r");
	if (fp == NULL) return -1;
	fscanf(fp, "%d %c", &N, &X);
	fclose(fp);

	begin = clock(); // timer start

	struct array **ar = draw(N); // generating structs

	sort(ar, N); // sorting by int

	printf("Letter '%c' found % d times\n\n", X, count(ar, N, X)); // counting letters

	for (int i = 0; i < 20; i++) { // 20 first structs
		printf("%d, %c, %f\n", ar[i]->integer, ar[i]->character, ar[i]->floating);
	}

	rem(ar, N); // freeing memory

	end = clock(); // timer stop
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime: %0.3fs\n", time_spent);

	return 0;
}