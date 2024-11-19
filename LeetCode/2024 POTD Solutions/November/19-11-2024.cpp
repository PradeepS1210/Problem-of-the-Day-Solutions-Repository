/*
Problem of the Day: 2461. Maximum Sum of Distinct Subarrays With Length K
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2461-maximum-sum-of-distinct-subarrays-with-length-k-leetcode-solution-771d3e7dc86f
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, currentSum = 0;
        unordered_map<int, int> freqMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            freqMap[nums[i]]++;

            if (i >= k) {
                currentSum -= nums[i - k];
                freqMap[nums[i - k]]--;
                if (freqMap[nums[i - k]] == 0) {
                    freqMap.erase(nums[i - k]);
                }
            }

            if (freqMap.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};