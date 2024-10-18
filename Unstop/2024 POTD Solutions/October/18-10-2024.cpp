/*
Problem of the Day: Maximum Profit — II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-profit-ii-unstop-solution-f4865f59b45f
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> price(N), weight(N);
    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> weight[i];
    }

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int w = weight[i]; w <= W; ++w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + price[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}
