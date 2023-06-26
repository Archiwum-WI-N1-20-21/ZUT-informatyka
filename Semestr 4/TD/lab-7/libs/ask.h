#ifndef ASK_H_
#define ASK_H_

double calculateH(double *ASKp, double A1, double A2, int N);
void modulateASK(double *output, int *input, double *time, int fn, double A1, double A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);
void demodulateASK(int *output, double *input, double *time, int fn, double A1, double A2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);

#endif