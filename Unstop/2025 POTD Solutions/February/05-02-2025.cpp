/*
Problem of the Day: The 3 jumps
Problem Description: https://unstop.com/code/practice/305422
*/

#include <bits/stdc++.h>
using namespace std;

int minCostToReachEnd(const vector<int>& V) {
    int N = V.size();
    if (N == 1) return 0;
    
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(V[i] - V[i - j]));
            }
        }
    }
    return dp[N - 1];
}

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    cout << minCostToReachEnd(V) << endl;
    return 0;
}
