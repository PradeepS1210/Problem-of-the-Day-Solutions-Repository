/*
Problem of the day: Longest Subarray with Sum K
Problem Description: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> sumMap;
        int currSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];

            if (currSum == k) {
                maxLength = i + 1;
            }

            if (sumMap.find(currSum - k) != sumMap.end()) {
                maxLength = max(maxLength, i - sumMap[currSum - k]);
            }

            if (sumMap.find(currSum) == sumMap.end()) {
                sumMap[currSum] = i;
            }
        }

        return maxLength;
    }
};