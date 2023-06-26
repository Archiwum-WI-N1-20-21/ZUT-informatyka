#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
				FILE* f;

				double arr1[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
				double arr2[10];

				f = fopen("dump.txt", "w");

				for (int i = 0; i < 10; i++) {
								arr2[i] = sin(arr1[i]);
								fprintf(f, "%f\n", arr2[i]);
				}

				fclose(f);

				return 0;
}