#include "utils.h"
#include "includes.h"

/* Printowanie tablicy DOUBLE do pliku */
void printDoubleToFile(char *name, double *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%f\n", array[i]);
	}

	fclose(fp);
}

/* Printowanie tablicy INT do pliku */
void printIntToFile(char *name, int *array, int N) {
	FILE *fp;

	fp = fopen(name, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d\n", array[i]);
	}

	fclose(fp);
}

/* Skrocenie ciagu do 10 bitow */
void truncate(char *input, int N) {
	int len = strlen(input);
	if (len > 10) {
		input[10] = '\0';
	}
}

/* String na int */
void stringToInt(char *input, int *output, int N) {
	for (int i = 0; i < N; i++) {
		if (input[i] == '0') {
			output[i] = 0;
		} else {
			output[i] = 1;
		}
	}
}

/* Binarny int na string */
void binaryIntToString(int *input, char *output, int N) {
    for (int i = 0; i < N; i++) {
        if (input[i] == 1) {
            output[i] = '1';
        }
        if (input[i] == 0) {
            output[i] = '0';
        }
    }
}

/* Generowanie tablicy czasu */
void generateTime(double *time, int fs, int N) {
	for (int i = 0; i < N; i++) {
		time[i] = (double)i / fs;
	}
}

/* Konwersja stringa na bity */
char* stringToBinary(char* input) {
    if (input == NULL) return 0;
    int len = strlen(input);
    char *binary = malloc(len * 7);
    binary[0] = '\0';
    for(int i = 0; i < len; ++i) {
        char ch = input[i];
        for(int j = 6; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

/* Konwersja sygnalu na bity (int) */
void signalToBinaryInt(int *signal, int *binary, int N, int n) {
	int a;
	int si = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		a = 0;
		if (signal[i] == 1) {
			a = 1;
		}
		if ((int)i/n != si) {
			binary[index] = a;
			index++;
		}
		si = (int)i/n;
	}
	binary[index] = a;
}

/* Konwersja sygnalu na bity */
void signalToBinary(int *signal, char *binary, int N, int n) {
	char a;
	int si = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		a = '0';
		if (signal[i] == 1) {
			a = '1';
		}
		if ((int)i/n != si) {
			sprintf(&binary[index], "%c", a);
			index++;
		}
		si = (int)i/n;
	}
	sprintf(&binary[index], "%c", a);
}

/* Konwersja bitow na string */
char* GetSubString(char* str, int index, int count) {
	int strLen = strlen(str);
	int lastIndex = index + count;

	if (index >= 0 && lastIndex > strLen) return "";

	char* subStr = malloc(count + 1);

	for (int i = 0; i < count; i++) {
		subStr[i] = str[index + i];
	}

	subStr[count] = '\0';

	return subStr;
}

char* AppendString(const char* str1, const char* str2) {
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	int strLen = str1Len + str2Len + 1;
	char* str = malloc(strLen);

	for (int i = 0; i < str1Len; i++)
		str[i] = str1[i];

	for (int i = 0; i < str2Len; i++)
		str[(str1Len + i)] = str2[i];

	str[strLen - 1] = '\0';

	return str;
}

char* CharToString(char c) {
	char* str = malloc(2);
	str[0] = c;
	str[1] = '\0';

	return str;
}

int BinaryToDecimal(char* bin)
{
	int binLength = strlen(bin);
	double dec = 0;

	for (int i = 0; i < binLength; ++i)
	{
		dec += (bin[i] - 48) * pow(2, ((binLength - i) - 1));
	}

	return (int)dec;
}

char* BinaryToASCII(char* bin) {
	char* ascii = "";
	int binLen = strlen(bin);

	for (int i = 0; i < binLen; i += 7)
	{
		ascii = AppendString(ascii, CharToString((char)BinaryToDecimal(GetSubString(bin, i, 7))));
	}

	return ascii;
}

/* Bialy szum */
void noise(double *signal, double alfa, int N, int MODULATION_TYPE, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		signal[i] = signal[i] + alfa * noiseGen();
	}

	if (MODULATION_TYPE == 1) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/ask_noise.txt", signal, N);
			system("plotting.py ask_noise.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/ask_noise.txt", signal, N);
			system("plotting.py ask_noise.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/ask_noise.txt", signal, N);
			system("plotting.py ask_noise.txt 0 1");
		}
	}

	if (MODULATION_TYPE == 2) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/psk_noise.txt", signal, N);
			system("plotting.py psk_noise.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/psk_noise.txt", signal, N);
			system("plotting.py psk_noise.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/psk_noise.txt", signal, N);
			system("plotting.py psk_noise.txt 0 1");
		}
	}

	if (MODULATION_TYPE == 3) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/fsk_noise.txt", signal, N);
			system("plotting.py fsk_noise.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/fsk_noise.txt", signal, N);
			system("plotting.py fsk_noise.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/fsk_noise.txt", signal, N);
			system("plotting.py fsk_noise.txt 0 1");
		}
	}
}

double noiseGen() {
  /* Generates additive white Gaussian Noise samples with zero mean and a standard deviation of 1. */
 
  double temp1;
  double temp2;
  double result;
  int p;

  p = 1;

  while(p > 0) {
	temp2 = (rand() / ((double)RAND_MAX ));

    if (temp2 == 0) {
      p = 1;
    }
    else {
       p = -1;
    }
  }

  temp1 = cos((2.0 * M_PI) * rand() / ((double)RAND_MAX ));
  result = sqrt(-2.0 * log(temp2 )) * temp1;

  return result;
}

/* Tlumienie */
void damping(double *signal, double *time, double beta, int N, int MODULATION_TYPE, int DISPLAY_GRAPH, int SAVE_GRAPH) {
	for (int i = 0; i < N; i++) {
		signal[i] = signal[i] * exp(-beta * time[i]);
	}

	if (MODULATION_TYPE == 1) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/ask_damping.txt", signal, N);
			system("plotting.py ask_damping.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/ask_damping.txt", signal, N);
			system("plotting.py ask_damping.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/ask_damping.txt", signal, N);
			system("plotting.py ask_damping.txt 0 1");
		}
	}

	if (MODULATION_TYPE == 2) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/psk_damping.txt", signal, N);
			system("plotting.py psk_damping.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/psk_damping.txt", signal, N);
			system("plotting.py psk_damping.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/psk_damping.txt", signal, N);
			system("plotting.py psk_damping.txt 0 1");
		}
	}

	if (MODULATION_TYPE == 3) {
		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 0) {
			printDoubleToFile("dumps/fsk_damping.txt", signal, N);
			system("plotting.py fsk_damping.txt 1 0");
		}

		if (DISPLAY_GRAPH == 1 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/fsk_damping.txt", signal, N);
			system("plotting.py fsk_damping.txt 1 1");
		}

		if (DISPLAY_GRAPH == 0 && SAVE_GRAPH == 1) {
			printDoubleToFile("dumps/fsk_damping.txt", signal, N);
			system("plotting.py fsk_damping.txt 0 1");
		}
	}
}

/* Kalkulacja stopy bledu */
void BER(char *sent, char *received, int N) {
	int E = 0;

	for (int i = 0; i < N; i++) {
		if (sent[i] != received[i]) {
			E++;
		}
	}

	printf("BER: %d/%d  %.2f%\n", E, N, (double)E/(double)N*100);
}