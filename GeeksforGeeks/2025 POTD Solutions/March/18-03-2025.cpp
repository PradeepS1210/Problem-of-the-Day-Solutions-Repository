/*
Problem of the Day: Partition Equal Subset Sum
Problem Description: https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
