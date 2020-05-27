//
// Created by Waitti on 2020/5/18.
//

#include "FastMul.h"

using namespace std;

void base_check(Int &a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        int t = *it / 10;
        *it = *it % 10;
        *(it + 1) += t;
    }
}

Int base_mul(Int &a, Int &b) {
    Int c(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] = a[i] * b[j];
        }
    }
    return c;
}

void print(Int &a) {
    for (auto i = a.rbegin(); i != a.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}