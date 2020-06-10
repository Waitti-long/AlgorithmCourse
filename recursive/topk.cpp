#include "topk.h"

using namespace std;

const int N = 1e4;
int sel = 0;

void find_mid(int a[], int l, int r) {
    if (r - l < 5)return;
    int k = 0;
    for (int i = l; i <= r - 5; i += 5) {
        sort(a + i, a + i + 5);
        swap(a[l + k], a[i + 2]);
        k++;
    }
    if (k <= 1)return;
    find_mid(a, l, k);
}

void select(int a[], int l, int r, int k) {
    if (l >= r)return;
    swap(a[l], a[l + rand() % (r - l)]);
    int t = a[l], i = l, j = r - 1;
    while (i < j) {
        while (i < j && a[j] >= t)j--;
        a[i] = a[j];
        while (i < j && a[i] < t)i++;
        a[j] = a[i];
    }
    a[i] = t;
    if (i == k)return;
    if (i < k)select(a, i + 1, r, k);
    else select(a, l, i, k);
}

int solve(int a[], int l, int r, int k,int se) {
    srand(now());
    sel  = se;
    select(a, l, r, k);
    return a[k];
}