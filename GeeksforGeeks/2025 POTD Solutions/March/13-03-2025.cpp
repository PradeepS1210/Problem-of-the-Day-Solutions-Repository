/*
Problem of the Day: 0 - 1 Knapsack Problem
Problem Description: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};
