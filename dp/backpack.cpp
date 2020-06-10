#include "backpack.h"

using namespace std;

int base_zero_one(int *dp, int c, int w, int V) {
    for (int v = V; v >= c; v--) {
        dp[v] = max(dp[v], dp[v - c] + w);
    }
}

int zero_one(const vector<int> &sizes, const vector<int> &values, int V) {
    int dp[sizes.size() + 10];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < sizes.size(); ++i) {
        base_zero_one(dp, sizes[i], values[i], V);
    }
    return dp[V];
}

int complete_backpack(const vector<int> &sizes, const vector<int> &values,int V){
    int dp[sizes.size() + 10];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < sizes.size(); ++i) {
        for(int v = sizes[i]; v <= V; v++){
            dp[v] = max(dp[v], dp[v - sizes[i]] + values[i]);
        }
    }
    return dp[V];
}
