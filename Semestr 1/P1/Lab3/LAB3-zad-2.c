#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


// Cos zepsulem, zle dziala generacja numerow do losowania kart i program za kazdym razem wybiera ta sama karte


void main() {
	int suma_gracz = 0;
	int suma_komputer = 0;
	int wartosc_karty_gracz;
	int wartosc_karty_komputer;
	int choice1, choice2;
	int ch;
	int generator;

	system("cls");
	srand(time(NULL));

	do {
		printf("Gra w oczko \n\n");
		puts("1. Dziewiatka");
		puts("2. Dziesiatka");
		puts("3. Walet");
		puts("4. Dama");
		puts("5. Krol");
		puts("6. As");
		puts("0. Exit");
		puts("Wybierz swoja pierwsza karte: ");
		scanf_s("%d", &choice1);
		ch = getchar();

		switch (choice1) {
		case 1:
			suma_gracz = suma_gracz + 0;
			break;
		case 2:
			suma_gracz = suma_gracz + 10;
			break;
		case 3:
			suma_gracz = suma_gracz + 2;
			break;
		case 4:
			suma_gracz = suma_gracz + 3;
			break;
		case 5:
			suma_gracz = suma_gracz + 4;
			break;
		case 6:
			suma_gracz = suma_gracz + 11;
			break;
		default:
			puts("Bledny wybor");
			break;
		}
		
		generator = rand() % 6;
		
		if (generator = 0) {
			suma_komputer = suma_komputer + 0;
		}
		else if (generator = 1) {
			suma_komputer = suma_komputer + 10;
		}
		else if (generator = 2) {
			suma_komputer = suma_komputer + 2;
		}
		else if (generator = 3) {
			suma_komputer = suma_komputer + 3;
		}
		else if (generator = 4) {
			suma_komputer = suma_komputer + 4;
		}
		else if (generator = 5) {
			suma_komputer = suma_komputer + 11;
		}

		do {
			system("cls");
			printf("Twoja suma kart: %d", suma_gracz);
			printf("\nSuma kart komputera: %d\n\n", suma_komputer);

			puts("1. Generuj nastepna karte");
			puts("0. Zakoncz gre");
			scanf_s("%d", &choice2);
			ch = getchar();

			switch (choice2) {
			case 1:
				generator = rand() % 6;
				if (generator = 0) {
					suma_komputer = suma_komputer + 0;
				}
				else if (generator = 1) {
					suma_komputer = suma_komputer + 10;
				}
				else if (generator = 2) {
					suma_komputer = suma_komputer + 2;
				}
				else if (generator = 3) {
					suma_komputer = suma_komputer + 3;
				}
				else if (generator = 4) {
					suma_komputer = suma_komputer + 4;
				}
				else if (generator = 5) {
					suma_komputer = suma_komputer + 11;
				}

				generator = rand() % 6;
				if (generator = 0) {
					suma_gracz = suma_gracz + 0;
				}
				else if (generator = 1) {
					suma_gracz = suma_gracz + 10;
				}
				else if (generator = 2) {
					suma_gracz = suma_gracz + 2;
				}
				else if (generator = 3) {
					suma_gracz = suma_gracz + 3;
				}
				else if (generator = 4) {
					suma_gracz = suma_gracz + 4;
				}
				else if (generator = 5) {
					suma_gracz = suma_gracz + 11;
				}
				printf("\n\nTwoja suma kart: %d", suma_gracz);
				printf("\nSuma kart komputera: %d", suma_komputer);
				break;

			case 0:
				if (suma_gracz > suma_komputer) {
					system("cls");
					printf("Wygrales\n\n");
				}
				else if (suma_komputer > suma_gracz) {
					system("cls");
					printf("Przegrales\n\n");
				}
				return EXIT_SUCCESS;
			}
		} while (choice2 != 0);

	} while (choice1 != 0);
}