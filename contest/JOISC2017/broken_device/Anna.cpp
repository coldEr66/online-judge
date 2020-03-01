#include "Annalib.h"

const int MAXn = 173;
int ok[MAXn],d[MAXn];
void Anna( int N, long long X, int K, int P[] ){
    for (int i=0;i<N;i++) {
        ok[i] = d[i] = 0;
    }
    for (int i=0;i<K;i++) {
        ok[P[i]] = 1;
    }

    for (int i=0;i<N;i+=3) {
        int tmp = ok[i] + ok[i+1] + ok[i+2];
        if (tmp >= 2) continue;
        if (tmp == 1) {
            if (X % 2 == 0) {
                if (ok[i+2]) d[i] = d[i+1] = 1;
                else d[i+2] = 1;
            }
            else {
                if (ok[i]) {
                    if (X % 4 == 1) d[i+1] = 1;
                    else d[i+1] = d[i+2] = 1;
                    X >>= 1;
                }
                else d[i] = 1;
            }
            X >>= 1;
        }
        else {
            if (X % 4 == 0) d[i] = d[i+1] = d[i+2] = 1;
            else if (X % 4 == 1) d[i+1] = 1;
            else if (X % 4 == 2) d[i] = d[i+2] = 1;
            else d[i+1] = d[i+2] = 1;
            X >>= 2;
        }
    }
    for (int i=0;i<N;i++) {
        Set(i, d[i]);
    }
}
