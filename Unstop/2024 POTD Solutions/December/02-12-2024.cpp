/*
Problem of the Day: The Prediction Reward
Problem Description: https://medium.com/@pradeepsooryavanshee1210/the-prediction-reward-unstop-solution-99497d8caea2
*/

#include <bits/stdc++.h>
using namespace std;

int getMinimumCoins(int N) {
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i <= N - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; ++k) {
                int cost = k;
                int left = (k > i) ? dp[i][k - 1] : 0;
                int right = (k < j) ? dp[k + 1][j] : 0;
                dp[i][j] = min(dp[i][j], cost + max(left, right));
            }
        }
    }
    
    return dp[1][N];
}

int main() {
    int N;
    cin >> N;
    cout << getMinimumCoins(N) << endl;
    return 0;
}