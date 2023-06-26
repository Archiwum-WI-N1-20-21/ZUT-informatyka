#ifndef PSK_H_
#define PSK_H_

void modulatePSK(double *output, int *input, double *time, int fn, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);
void demodulatePSK(int *output, double *input, double *time, int fn, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);

#endif