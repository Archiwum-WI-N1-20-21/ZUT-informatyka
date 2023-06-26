#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;
int tablica[9];
int suma = 0;
int suma_dod = 0;
int suma_uj = 0;
int suma_k = 0;
int k;
int suma_parz = 0;
int suma_n_parz = 0;

int tablica2[100][100];
int m, n, x, y;

//1.1
void wczytaj_tablice() {
    puts("Podaj 10 liczb");
	for (int i = 0; i < 10; i++) {
		puts("Podaj liczbe: ");
		scanf("%d", &tablica[i]);
        system("cls");
	}
	puts("Podane wartosci: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", tablica[i]);
	}
}

void wyswietl(int liczba) {
    printf("%d", liczba);
}

int suma_wszystkich(int liczby[]) {
    for (int i = 0; i < 10; i++) {
		suma = suma + liczby[i];
	}
	printf("\n\nSuma wszystkich elementow: %d", suma);
}

void suma_dodatnich(int liczby[]) {
    for (int i = 0; i < 10; i++) {
		if (liczby[i] > 0) {
			suma_dod += liczby[i];
		}
	}
	printf("\n\nSuma elementow dodatnich: %d", suma_dod);
}

void suma_ujemnych(int liczby[]) {
    for (int i = 0; i < 10; i++) {
		if (liczby[i] < 0) {
			suma_uj += liczby[i];
		}
	}
	printf("\n\nSuma elementow ujemnych: %d", suma_uj);
}

void suma_wiekszych_od_k(int liczby[]) {
    puts("\n\nPodaj k: ");
    scanf("%d", &k);
    for (int i = 0; i < 10; i++) {
		if (liczby[i] > k) {
			suma_k += liczby[i];
		}
	}
	printf("Suma elementow wiekszych od k: %d", suma_k);
}

void suma_parzystych(int liczby[]) {
    for (int i = 0; i < 10; i+=2) {
		suma_parz += liczby[i];
	}
    printf("\n\nSuma elementow o parzystych indeksach: %d", suma_parz);
}

void suma_nieparzystych(int liczby[]) {
    for (int i = 1; i < 10; i+=2) {
		suma_n_parz += liczby[i];
	}
    printf("\n\nSuma elementow o nieparzystych indeksach: %d\n\n", suma_n_parz);
}

//1.2
int wypelnij_tablice() {
    puts("Podaj M:");
    scanf("%d", &m);
    puts("Podaj N:");
    scanf("%d", &n);
    for (x = 0; x < m; x++) {
        for (y = 0; y < n; y++) {
            tablica2[m][n] = rand();
        }
    }
    puts("\n");
    for (x = 0; x < m; x++) {
        for (y = 0; y < n; y++) {
            printf("%d ", tablica2[m][n]);
        }
        printf("\n");
    }
    return tablica2;
}


int main() {
    srand(time(NULL));

    // 1.1
    wczytaj_tablice();
	suma_wszystkich(tablica);
    suma_dodatnich(tablica);
    suma_ujemnych(tablica);
    suma_wiekszych_od_k(tablica);
    suma_parzystych(tablica);
    suma_nieparzystych(tablica);

    //1.2
    wypelnij_tablice();

	return 0;
}
