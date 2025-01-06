/*
Asked in Zoho, Walmart
Problem of the Day: Removing Balls
Problem Description: https://unstop.com/code/practice/250896
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string winner(vector<int>& balls) {
        int n = balls.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + balls[i];
        }

        for (int i = 0; i < n; ++i) {
            dp[i][i] = balls[i];
        }

        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                int totalBalls = prefixSum[j + 1] - prefixSum[i];

                dp[i][j] = max(
                    totalBalls - dp[i + 1][j],
                    totalBalls - dp[i][j - 1]
                );
            }
        }

        int aryanScore = dp[0][n - 1];
        int totalBalls = prefixSum[n];
        int ankitScore = totalBalls - aryanScore;

        return (aryanScore >= ankitScore) ? "Aryan" : "Ankit";
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> balls(n);

    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    Solution solution;
    cout << solution.winner(balls) << endl;

    return 0;
}