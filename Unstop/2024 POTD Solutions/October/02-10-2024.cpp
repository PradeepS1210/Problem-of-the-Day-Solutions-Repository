/*
Problem of the Day: Scheduling
Problem Description: https://medium.com/@pradeepsooryavanshee1210/scheduling-unstop-solution-dfd018f3064e
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int minDifficulty(vector<int>& tasks, int D) {
    int N = tasks.size();
    if (N < D) return -1;

    vector<vector<int>> dp(N + 1, vector<int>(D + 1, INT_MAX));
    
    dp[0][0] = 0;

    for (int d = 1; d <= D; d++) {
        for (int i = 1; i <= N; i++) {
            int maxDifficulty = 0;
            for (int k = i; k >= 1; k--) {
                maxDifficulty = max(maxDifficulty, tasks[k - 1]);
                if (dp[k - 1][d - 1] != INT_MAX) {
                    dp[i][d] = min(dp[i][d], dp[k - 1][d - 1] + maxDifficulty);
                }
            }
        }
    }
    
    return dp[N][D] == INT_MAX ? -1 : dp[N][D];
}

int main() {
    int B;
    cin >> B;
    vector<int> tasks(B);
    
    for (int i = 0; i < B; i++) {
        cin >> tasks[i];
    }

    int D;
    cin >> D;

    cout << minDifficulty(tasks, D) << endl;
    return 0;
}