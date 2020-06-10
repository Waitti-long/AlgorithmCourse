#include "ImageComparision.h"

using namespace std;


inline int len(int i) {
    int k = 1;
    i /= 2;
    while (i)k++, i /= 2;
    return k;
}


void compress(int n, int p[], int s[], int l[], int b[]) {
    int Lmax = 256, header = 11;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = len(p[i]);
        int bmax = b[i];
        s[i] = s[i - 1] + bmax;
        l[i] = 1;
        for (int j = 2; j <= i && j <= Lmax; j++) {
            if (bmax < b[i - j + 1])bmax = b[i - j + 1];
            if (s[i] > s[i - j] + j * bmax) {
                s[i] = s[i - j] + j * bmax;
                l[i] = j;
            }
        }
        s[i] += header;
    }
}