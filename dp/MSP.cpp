#include "MSP.h"


using namespace std;

int msp(const int a[], int n) {
    const int INF = 0x3f3f3f3f;
    int max_sum = -INF, tmp = 0;
    for (int i = 0; i < n; ++i) {
        tmp = max(tmp + a[i], a[i]);
        max_sum = max(max_sum, tmp);
    }
    return max_sum;
}

typedef pair<int, int> PI;
const int INF = 0x3f3f3f3f;

vector<PI> hm(int b[], int n) {
    int a[n];
    memcpy(a, b, sizeof a);
    int max_tmp = 0, max_v = -INF;
    for (auto &i: a) {
        max_tmp = max(max_tmp + i, i);
        max_v = max(max_v, max_tmp);
    }
    max_tmp = 0;
    int last = 0;
    bool can_choose = true;
    vector<PI> res;
    for (int i = 0; i < n; ++i) {
        if (max_tmp > 0) { // >=
            max_tmp = max_tmp + a[i];
        } else {
            max_tmp = a[i];
            can_choose = true;
            last = i;
        }
        if (max_tmp == max_v && can_choose) {
            int from = last, to = i;
//            while (a[from] == 0 && from < to)from++;
//            while (a[to] == 0 && from < to)to--;
            for (int j = from; j <= to; ++j) {
                if (a[j] > 0) {
                    res.emplace_back(from, to);
                    can_choose = false;
                    max_tmp = 0;
                    last = i + 1;
                    break;
                }
            }
        }
    }
    return res;
}