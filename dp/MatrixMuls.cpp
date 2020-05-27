#include "MatrixMuls.h"

using namespace std;

int run(const int a[], int n) {
    int b[n - 1][n - 1],c[n - 1][n - 1];
    memset(b, 0x3f, sizeof b);

    for (int i = 0; i < n - 1; ++i) {
        b[i][i] = 0;
        b[i][i + 1] = a[i] * a[i + 1] * a[i + 2];
    }

    for (int i = 2; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int from = j, to = i + j;
            int min_v = b[from][to];
            for (int k = from; k < to; ++k) {
                min_v = min(min_v, b[from][k] + b[k + 1][to] + a[from] * a[k + 1] * a[to + 1]);
            }
            b[from][to] = min_v;
        }
    }
    return b[0][n - 2];
}
