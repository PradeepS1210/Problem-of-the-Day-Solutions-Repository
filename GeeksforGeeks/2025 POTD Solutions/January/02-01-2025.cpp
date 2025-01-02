/*
Asked in Microsoft
Problem of the Day: Subarrays with sum K
Problem Description: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1
*/

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, prefixSum = 0;
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};