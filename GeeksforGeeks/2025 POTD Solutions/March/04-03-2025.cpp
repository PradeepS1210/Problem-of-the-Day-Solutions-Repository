/*
Problem of the Day: Longest Increasing Subsequence
Problem Description: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/


class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
