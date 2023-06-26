// compile gcc -I./ -o src .\src.c libs/*.c

#include "libs/includes.h"
#include "libs/utils.h"
#include "libs/dft.h"
#include "libs/hamming.h"
#include "libs/ask.h"
#include "libs/psk.h"
#include "libs/fsk.h"

void ASK(char *message, int hamming, int noiseEnabled, double alfa, int dampingEnabled, double beta, int tb, int W, int fs, double A1, double A2, int DEBUG_PRINTS, int DISPLAY_GRAPHS, int SAVE_GRAPHS) {
	if (strlen(message) < 1) return;
	if (hamming >= 1 && hamming <= 0) return;
	if (noiseEnabled >= 1 && noiseEnabled <= 0) return;
	if (dampingEnabled >= 1 && dampingEnabled <= 0) return;
	if (DISPLAY_GRAPHS >= 1 && DISPLAY_GRAPHS <= 0) return;
	if (SAVE_GRAPHS >= 1 && SAVE_GRAPHS <= 0) return;

	printf("\nASK:\n");
	if (hamming == 0) printf("Hamming 7-4\n");
	if (hamming == 1) printf("Hamming 15-11\n");

	int sLen = strlen(message);
	int messageInt[sLen];
	
	// Zmiana ciagu bitow z charow na inty
	stringToInt(message, messageInt, sLen);

	// Obliczanie liczby ramek
	int HD = 0;
	int HC = 0;
	if (hamming == 0) {
		HD = 4;
		HC = 7;
	} else {
		HD = 11;
		HC = 15;
	}

	int columns = 1;
	if (sLen % HD == 0) {
		columns = sLen / HD;
	} else {
		columns = (sLen / HD) + 1;
	}

	int hamming_frames[columns][HD];
	memset(hamming_frames, 0, (columns) * HD * sizeof(int));

	// Podzielenie ciagu bitow na ramki
	int k = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < HD; j++) {
			hamming_frames[i][j] = messageInt[k];
			k++;
			if (k == sLen) break;
		}
	}

	if (DEBUG_PRINTS == 1) {
		printf("\nRamki do kodera:\n");
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HD; j++) {
				printf("%d", hamming_frames[i][j]);
			}
			printf("\n");
		}
	}

	// Kodowanie
	int hamming_temp_7[HC];
	int coded[columns * HC];
	k = 0;
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			hamming74Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			hamming1511Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	printf("\nWiadomosc po kodowaniu:\n");
	for (int i = 0; i < columns * HC; i++) {
		printf("%d", coded[i]);
	}

	// Modulacja
	int tc = tb * (columns * HC);
	double fn = W / tb;
	int n = tb * fs;
	int N = tc * fs;

	double time[N];
	generateTime(time, fs, N);
	printDoubleToFile("dumps/time.txt", time, N);

	double modulatedASK[N];
	modulateASK(modulatedASK, coded, time, fn, A1, A2, N, DISPLAY_GRAPHS, SAVE_GRAPHS);

	// Szum
	if (noiseEnabled == 1) {
		noise(modulatedASK, alfa, N, 1, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Tlumienie
	if (dampingEnabled == 1) {
		damping(modulatedASK, time, beta, N, 1, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Demodulacja
	int demodulatedASK[N];
	demodulateASK(demodulatedASK, modulatedASK, time, fn, A1, A2, N, DISPLAY_GRAPHS, SAVE_GRAPHS);
	int recievedASK[columns * HC];
	signalToBinaryInt(demodulatedASK, recievedASK, N, n);

	// Dekodowanie
	int hamming_temp[HD];
	int decoded[columns * HD];
	k = 0;
	int l = 0;
	
	if (DEBUG_PRINTS == 1) printf("\n\nRamki do dekodera:\n");
	
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedASK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming74Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedASK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming1511Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	printf("\nWiadomosc po odkodowaniu:\n");
	for (int i = 0; i < columns * HD; i++) {
		printf("%d", decoded[i]);
	}

	char slowo[(sLen * 7) + 1];
	memset(slowo, 0, (sLen * 7) + 1);
	binaryIntToString(decoded, slowo, columns * HD);
	printf("\n\nOdebrana wiadomosc: %s", slowo);
	printf("\nOdebrane slowo:     %s\n", BinaryToASCII(slowo));
	if (noiseEnabled == 1) {
		printf("Bialy szum: %.2f\n", alfa);
	} else {
		printf("Bialy szum: Wylaczony\n");
	}
	if (dampingEnabled == 1) {
		printf("Tlumienie: %.2f\n", beta);
	} else {
		printf("Tlumienie: Wylaczone\n");
	}
	BER(message, slowo, sLen);
}

void FSK(char *message, int hamming, int noiseEnabled, double alfa, int dampingEnabled, double beta, int tb, int W, int fs, int fn1, int fn2, int DEBUG_PRINTS, int DISPLAY_GRAPHS, int SAVE_GRAPHS) {
	if (strlen(message) < 1) return;
	if (hamming >= 1 && hamming <= 0) return;
	if (noiseEnabled >= 1 && noiseEnabled <= 0) return;
	if (dampingEnabled >= 1 && dampingEnabled <= 0) return;
	if (DISPLAY_GRAPHS >= 1 && DISPLAY_GRAPHS <= 0) return;
	if (SAVE_GRAPHS >= 1 && SAVE_GRAPHS <= 0) return;

	printf("\nFSK:\n");
	if (hamming == 0) printf("Hamming 7-4\n");
	if (hamming == 1) printf("Hamming 15-11\n");

	int sLen = strlen(message);
	int messageInt[sLen];
	
	// Zmiana ciagu bitow z charow na inty
	stringToInt(message, messageInt, sLen);

	// Obliczanie liczby ramek
	int HD = 0;
	int HC = 0;
	if (hamming == 0) {
		HD = 4;
		HC = 7;
	} else {
		HD = 11;
		HC = 15;
	}

	int columns = 1;
	if (sLen % HD == 0) {
		columns = sLen / HD;
	} else {
		columns = (sLen / HD) + 1;
	}

	int hamming_frames[columns][HD];
	memset(hamming_frames, 0, (columns) * HD * sizeof(int));

	// Podzielenie ciagu bitow na ramki
	int k = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < HD; j++) {
			hamming_frames[i][j] = messageInt[k];
			k++;
			if (k == sLen) break;
		}
	}

	if (DEBUG_PRINTS == 1) {
		printf("\nRamki do kodera:\n");
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HD; j++) {
				printf("%d", hamming_frames[i][j]);
			}
			printf("\n");
		}
	}

	// Kodowanie
	int hamming_temp_7[HC];
	int coded[columns * HC];
	k = 0;
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			hamming74Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			hamming1511Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	printf("\nWiadomosc po kodowaniu:\n");
	for (int i = 0; i < columns * HC; i++) {
		printf("%d", coded[i]);
	}

	// Modulacja
	int tc = tb * (columns * HC);
	double fn = W / tb;
	int n = tb * fs;
	int N = tc * fs;

	double time[N];
	generateTime(time, fs, N);
	printDoubleToFile("dumps/time.txt", time, N);

	double modulatedFSK[N];
	modulateFSK(modulatedFSK, coded, time, fn1, fn2, N, DISPLAY_GRAPHS, SAVE_GRAPHS);

	// Szum
	if (noiseEnabled == 1) {
		noise(modulatedFSK, alfa, N, 3, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Tlumienie
	if (dampingEnabled == 1) {
		damping(modulatedFSK, time, beta, N, 3, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Demodulacja
	int demodulatedFSK[N];
	demodulateFSK(demodulatedFSK, modulatedFSK, time, fn1, fn2, N, DISPLAY_GRAPHS, SAVE_GRAPHS);
	int recievedFSK[columns * HC];
	signalToBinaryInt(demodulatedFSK, recievedFSK, N, n);

	// Dekodowanie
	int hamming_temp[HD];
	int decoded[columns * HD];
	k = 0;
	int l = 0;
	
	if (DEBUG_PRINTS == 1) printf("\n\nRamki do dekodera:\n");
	
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedFSK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming74Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedFSK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming1511Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	printf("\nWiadomosc po odkodowaniu:\n");
	for (int i = 0; i < columns * HD; i++) {
		printf("%d", decoded[i]);
	}

	char slowo[(sLen * 7) + 1];
	memset(slowo, 0, (sLen * 7) + 1);
	binaryIntToString(decoded, slowo, columns * HD);
	printf("\n\nOdebrana wiadomosc: %s", slowo);
	printf("\nOdebrane slowo:     %s\n", BinaryToASCII(slowo));
	if (noiseEnabled == 1) {
		printf("Bialy szum: %.2f\n", alfa);
	} else {
		printf("Bialy szum: Wylaczony\n");
	}
	if (dampingEnabled == 1) {
		printf("Tlumienie: %.2f\n", beta);
	} else {
		printf("Tlumienie: Wylaczone\n");
	}
	BER(message, slowo, sLen);
}

void PSK(char *message, int hamming, int noiseEnabled, double alfa, int dampingEnabled, double beta, int tb, int W, int fs, int DEBUG_PRINTS, int DISPLAY_GRAPHS, int SAVE_GRAPHS) {
	if (strlen(message) < 1) return;
	if (hamming >= 1 && hamming <= 0) return;
	if (noiseEnabled >= 1 && noiseEnabled <= 0) return;
	if (dampingEnabled >= 1 && dampingEnabled <= 0) return;
	if (DISPLAY_GRAPHS >= 1 && DISPLAY_GRAPHS <= 0) return;
	if (SAVE_GRAPHS >= 1 && SAVE_GRAPHS <= 0) return;

	printf("\nPSK:\n");
	if (hamming == 0) printf("Hamming 7-4\n");
	if (hamming == 1) printf("Hamming 15-11\n");

	int sLen = strlen(message);
	int messageInt[sLen];
	
	// Zmiana ciagu bitow z charow na inty
	stringToInt(message, messageInt, sLen);

	// Obliczanie liczby ramek
	int HD = 0;
	int HC = 0;
	if (hamming == 0) {
		HD = 4;
		HC = 7;
	} else {
		HD = 11;
		HC = 15;
	}

	int columns = 1;
	if (sLen % HD == 0) {
		columns = sLen / HD;
	} else {
		columns = (sLen / HD) + 1;
	}

	int hamming_frames[columns][HD];
	memset(hamming_frames, 0, (columns) * HD * sizeof(int));

	// Podzielenie ciagu bitow na ramki
	int k = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < HD; j++) {
			hamming_frames[i][j] = messageInt[k];
			k++;
			if (k == sLen) break;
		}
	}

	if (DEBUG_PRINTS == 1) {
		printf("\nRamki do kodera:\n");
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HD; j++) {
				printf("%d", hamming_frames[i][j]);
			}
			printf("\n");
		}
	}

	// Kodowanie
	int hamming_temp_7[HC];
	int coded[columns * HC];
	k = 0;
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			hamming74Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			hamming1511Coder(hamming_frames[i], hamming_temp_7);
			for (int j = 0; j < HC; j++) {
				coded[k] = hamming_temp_7[j];
				k++;
			}
		}
	}

	printf("\nWiadomosc po kodowaniu:\n");
	for (int i = 0; i < columns * HC; i++) {
		printf("%d", coded[i]);
	}

	// Modulacja
	int tc = tb * (columns * HC);
	double fn = W / tb;
	int n = tb * fs;
	int N = tc * fs;

	double time[N];
	generateTime(time, fs, N);
	printDoubleToFile("dumps/time.txt", time, N);

	double modulatedPSK[N];
	modulatePSK(modulatedPSK, coded, time, fn, N, DISPLAY_GRAPHS, SAVE_GRAPHS);

	// Szum
	if (noiseEnabled == 1) {
		noise(modulatedPSK, alfa, N, 2, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Tlumienie
	if (dampingEnabled == 1) {
		damping(modulatedPSK, time, beta, N, 2, DISPLAY_GRAPHS, SAVE_GRAPHS);
	}

	// Demodulacja
	int demodulatedPSK[N];
	demodulatePSK(demodulatedPSK, modulatedPSK, time, fn, N, DISPLAY_GRAPHS, SAVE_GRAPHS);
	int recievedPSK[columns * HC];
	signalToBinaryInt(demodulatedPSK, recievedPSK, N, n);

	// Dekodowanie
	int hamming_temp[HD];
	int decoded[columns * HD];
	k = 0;
	int l = 0;
	
	if (DEBUG_PRINTS == 1) printf("\n\nRamki do dekodera:\n");
	
	if (hamming == 0) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedPSK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming74Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	if (hamming == 1) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < HC; j++) {
				hamming_temp_7[j] = recievedPSK[k];
				k++;
			}
			if (DEBUG_PRINTS == 1) {
				for (int j = 0; j < HC; j++) {
					printf("%d", hamming_temp_7[j]);
				}
				printf("\n");
			}
			hamming1511Decoder(hamming_temp_7, hamming_temp);
			for (int x = 0; x < HD; x++) {
				decoded[l] = hamming_temp[x];
				l++;
			}
		}
	}

	printf("\nWiadomosc po odkodowaniu:\n");
	for (int i = 0; i < columns * HD; i++) {
		printf("%d", decoded[i]);
	}

	char slowo[(sLen * 7) + 1];
	memset(slowo, 0, (sLen * 7) + 1);
	binaryIntToString(decoded, slowo, columns * HD);
	printf("\n\nOdebrana wiadomosc: %s", slowo);
	printf("\nOdebrane slowo:     %s\n", BinaryToASCII(slowo));
	if (noiseEnabled == 1) {
		printf("Bialy szum: %.2f\n", alfa);
	} else {
		printf("Bialy szum: Wylaczony\n");
	}
	if (dampingEnabled == 1) {
		printf("Tlumienie: %.2f\n", beta);
	} else {
		printf("Tlumienie: Wylaczone\n");
	}
	BER(message, slowo, sLen);
}

int main(void) {
	srand(time(NULL));

	int tb = 1;
	int W = 2;
	int fs = 200;
	double A1 = 1;
	double A2 = 1.5;
	int fn1 = 1;
	int fn2 = 10;

	double alfa = 0.8;
	double beta = 6.0;

	char slowo[] = "Elo Mordeczki";
	printf("Nadane slowo:      %s\n", slowo);
	char *message = stringToBinary(slowo);
	printf("Nadane binarnie:   %s\n", message);

	ASK(message, 1, 1, alfa, 0, beta, tb, W, fs, A1, A2, 1, 0, 1);
	FSK(message, 0, 1, alfa, 1, beta, tb, W, fs, fn1, fn2, 0, 0, 1);
	PSK(message, 1, 1, alfa, 1, beta, tb, W, fs, 0, 0, 1);

	free(message);

	return 0;
}