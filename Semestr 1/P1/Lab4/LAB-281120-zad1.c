#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int i, j;
int tablica[9];
int suma = 0;
int suma_dodatnich = 0;
int suma_ujemnych = 0;
int suma_k = 0;
int k;

void main() {
	puts("Podaj 10 liczb");
	for (int i = 0; i < 10; i++) {
		puts("Podaj liczbe: ");
		scanf_s("%d", &tablica[i]);
	}
	puts("\nPodane wartosci: ");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", tablica[i]);
	}
	
	for (int i = 0; i < 10; i++) {
		suma = suma + tablica[i];
	}
	printf("\nSuma: %d", suma);

	for (int i = 0; i < 10; i++) {
		if (tablica[i] > 0) {
			suma_dodatnich = suma_dodatnich + tablica[i];
		}
	}
	printf("\nSuma elementow dodatnich: %d", suma_dodatnich);

	for (int i = 0; i < 10; i++) {
		if (tablica[i] < 0) {
			suma_ujemnych = suma_ujemnych + tablica[i];
		}
	}
	printf("\nSuma elementow ujemnych: %d", suma_ujemnych);

	puts("\nPodaj k:");
	scanf_s("%d", &k);
	for (int i = 0; i < 10; i++) {
		if (tablica[i] > k) {
			suma_k = suma_k + tablica[i];
		}
	}
	printf("Suma elementow wiekszych od k: %d", suma_k);
}