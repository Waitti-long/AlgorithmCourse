//
// Created by Waitti on 2020/5/27.
//

#include "LCS.h"

using namespace std;

int lcs(const string &a, const string &b) {
    int n1 = a.length(), n2 = b.length();
    if (!n1 || !n2)return 0;
    int c[n1 + 1][n2 + 1];
    for (int i = 0; i < n1 + 1; i++)
        for (int j = 0; j < n2 + 1; ++j)
            c[i][j] = (i == 0 || j == 0) ? 0 : (a[i] == b[j]) ? c[i - 1][j - 1] + 1 : max(c[i - 1][j], c[i][j - 1]);
    return c[n1][n2];
}