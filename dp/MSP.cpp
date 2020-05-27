#include "MSP.h"


using namespace std;

int msp(const int a[], int n) {
    const int INF = 0x3f3f3f3f;
    int max_sum = -INF, tmp = -INF;
    for (int i = 0; i < n; ++i) {
        tmp = max(tmp + a[i], a[i]);
        max_sum = max(max_sum, tmp);
    }
    return max_sum;
}
