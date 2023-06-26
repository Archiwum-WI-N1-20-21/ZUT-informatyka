#include "hamming.h"
#include "includes.h"

/* Kodowanie Hamminga 7-4 */ 
void hamming74Coder(int *input, int *output) {
	for (int i = 0; i < 4; i++) {
		if (input[i] > 1 || input[i] < 0) {
			input[i] = 0;
		}
	}

	output[2] = input[0];
	output[4] = input[1];
	output[5] = input[2];
	output[6] = input[3];
	output[0] = (output[2] + output[4] + output[6]) % 2;
	output[1] = (output[2] + output[5] + output[6]) % 2;
	output[3] = (output[4] + output[5] + output[6]) % 2;
}

/* Dekodowanie Hamminga 7-4 */
void hamming74Decoder(int *input, int *output) {
	int x1 = (input[0] + (input[2] + input[4] + input[6]) % 2) % 2;
	int x2 = (input[1] + (input[2] + input[5] + input[6]) % 2) % 2;
	int x4 = (input[3] + (input[4] + input[5] + input[6]) % 2) % 2;

	int s = (x1 * 1) + (x2 * 2) + (x4 * 4);

	if (input[s-1] == 0) {
		input[s-1] == 1;
	} else {
		input[s-1] == 0;
	}

	if (s != 0) {
		x1 = ((input[2] + input[4] + input[6]) % 2) % 2;
		x2 = ((input[2] + input[5] + input[6]) % 2) % 2;
		x4 = ((input[4] + input[5] + input[6]) % 2) % 2;

		s = (x1 * 1) + (x2 * 2) + (x4 * 4); 
	}

	output[0] = input[2];
	output[1] = input[4];
	output[2] = input[5];
	output[3] = input[6];
}

/* Kodowanie Hamminga 15-11 */
void hamming1511Coder(int *input, int *output) {
	int x1 = (input[0] + input[1] + input[3] + input[4] + input[6] + input[8] + input[10]) % 2;
	int x2 = (input[0] + input[2] + input[3] + input[5] + input[6] + input[9] + input[10]) % 2;
	int x4 = (input[1] + input[2] + input[3] + input[7] + input[8] + input[9] + input[10]) % 2;
	int x8 = (input[4] + input[5] + input[6] + input[7] + input[8] + input[9] + input[10]) % 2;

	output[0] = x1;
	output[1] = x2;
	output[2] = input[0];
	output[3] = x4;
	output[4] = input[1];
	output[5] = input[2];
	output[6] = input[3];
	output[7] = x8;
	output[8] = input[4];
	output[9] = input[5];
	output[10] = input[6];
	output[11] = input[7];
	output[12] = input[8];
	output[13] = input[9];
	output[14] = input[10];
}

/* Dekodowanie Hamminga 15-11 */
void hamming1511Decoder(int *input, int *output) {
	int xp1 = (input[2] + input[4] + input[6] + input[8] + input[10] + input[12] + input[14]) % 2;
	int xp2 = (input[2] + input[5] + input[6] + input[9] + input[10] + input[13] + input[14]) % 2;
	int xp4 = (input[4] + input[5] + input[6] + input[11] + input[12] + input[13] + input[14]) % 2;
	int xp8 = (input[8] + input[9] + input[10] + input[11] + input[12] + input[13] + input[14]) % 2;

	int xn1 = (input[0] + xp1) % 2;
	int xn2 = (input[1] + xp2) % 2;
	int xn4 = (input[3] + xp4) % 2;
	int xn8 = (input[7] + xp8) % 2;

	int S = xn1 * 1 + xn2 * 2 + xn4 * 4 + xn8 * 8;

	if (S != 0) {
		if (input[S-1] == 0) {
			input[S-1] == 1;
		} else {
			input[S-1] == 0;
		}
	}

	output[0] = input[2];
	output[1] = input[4];
	output[2] = input[5];
	output[3] = input[6];
	output[4] = input[8];
	output[5] = input[9];
	output[6] = input[10];
	output[7] = input[11];
	output[8] = input[12];
	output[9] = input[13];
	output[10] = input[14];
}