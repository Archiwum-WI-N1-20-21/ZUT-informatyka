#include <stdio.h>
#include <math.h>
int main() {
    int m1=1; 
    int m2=3;
    int c1=53; 
    int c2=25; 
    int k0=12;
    int n1, n2;
    float N, k1;
    
    for (n1=0; n1<10; ++n1) {
        for (n2=0; n2<10; ++n2) {
        N = (float) (m1 * (c1 - c2) - c1 * (m1 - m2) + k0 * (m1 - m2)) / (n1 * (m1 - m2) - m1 * (n1 - n2)); 
        k1 = (float) (n1 * N +c1 - k0) / m1;
        if (N > 0 && (floor(N) == N) && N < 128 && k1 <128) printf ("%3f %3f %d\n", N, k1, k0); 
        } 
    }

    return 0;
}