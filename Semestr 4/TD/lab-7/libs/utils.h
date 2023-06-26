#ifndef UTILS_H_
#define UTILS_H_

void printDoubleToFile(char *name, double *array, int N);
void printIntToFile(char *name, int *array, int N);
void truncate(char *input, int N);
void stringToInt(char *input, int *output, int N);
void binaryIntToString(int *input, char *output, int N);
void generateTime(double *time, int fs, int N);
char* stringToBinary(char* input);
void signalToBinaryInt(int *signal, int *binary, int N, int n);
void signalToBinary(int *signal, char *binary, int N, int n);
char* GetSubString(char* str, int index, int count);
char* AppendString(const char* str1, const char* str2);
char* CharToString(char c);
int BinaryToDecimal(char* bin);
char* BinaryToASCII(char* bin);
void noise(double *signal, double alfa, int N, int MODULATION_TYPE, int DISPLAY_GRAPH, int SAVE_GRAPH);
double noiseGen();
void damping(double *signal, double *time, double beta, int N, int MODULATION_TYPE, int DISPLAY_GRAPH, int SAVE_GRAPH);
void BER(char *sent, char *received, int N);

#endif