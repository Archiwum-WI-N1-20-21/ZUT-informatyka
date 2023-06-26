#ifndef FSK_H_
#define FSK_H_

void modulateFSK(double *output, int *input, double *time, int f1, int f2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);
void demodulateFSK(int *output, double *input, double *time, int f1, int f2, int N, int DISPLAY_GRAPH, int SAVE_GRAPH);

#endif