/*
Problem of the Day: Indexes of Subarray Sum
Problem Description: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
*/

class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int current_sum = arr[0], start = 0;

        for (int i = 1; i <= n; i++) {
            while (current_sum > target && start < i - 1) {
                current_sum -= arr[start];
                start++;
            }
            if (current_sum == target) {
                return {start + 1, i};
            }
            if (i < n) {
                current_sum += arr[i];
            }
        }
        return {-1};
    }
};