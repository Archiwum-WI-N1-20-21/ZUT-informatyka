#ifndef DFT_H_
#define DFT_H_

struct complexnum {
	double re;
	double im;
};

void dft(struct complexnum *cplx, double *input, int N);
void amplitudeSpectrum(struct complexnum *cplx, double *AS, int N);
void amplitudeSpectrumDb(double *AS, double *ASdb, int N);

#endif