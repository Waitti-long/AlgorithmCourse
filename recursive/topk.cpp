#include "topk.h"

using namespace std;

void random_select(int *a, int l, int r) {
    srand((unsigned int) time(nullptr));
    int idx = rand() % (r - l) + l;
    swap(a[l], a[idx]);
}

void linear_select(int *a, int l, int r) {
    typedef pair<int, int> PI;
    PI t[(r - l - 4) / 5];
    int k = 0;
    for (int i = l; i < (r - l - 4) / 5; i++) {
        sort(a + i, a + i + 5);
        t[k++] = {a[min(i + 2, r)], min(i + 2, r)};
    }
    sort(t, t + k);
    swap(a[0], a[t[k / 2].second]);
}

void select(int *a, int l, int r, int k, int func) {
    if (l < r) {
        if (func == 1) {
            random_select(a, l, r);
        } else if (func == 2) {
            linear_select(a, l, r);
        }
        int i = l, j = r;
        int t = a[l];
        while (i < j) {
            while (i < j && a[j] >= t)j--;
            if (i < j)a[i] = a[j], i++;
            while (i < j && a[i] < t)i++;
            if (i < j)a[j] = a[i], j--;
        }
        a[i] = t;
        if (i == k) {
            return;
        } else if (i < k) {
            select(a, i + 1, r, k, func);
        } else {
            select(a, l, i - 1, k, func);
        }
    }
}
