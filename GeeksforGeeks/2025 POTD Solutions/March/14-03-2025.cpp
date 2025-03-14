/*
Problem of the Day: Coin Change (Count Ways)
Problem Description: https://www.geeksforgeeks.org/problems/coin-change2448/1
*/

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[sum];
    }
};
