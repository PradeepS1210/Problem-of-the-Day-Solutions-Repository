/*
Problem of the Day: 2563. Count the Number of Fair Pairs
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2563-count-the-number-of-fair-pairs-leetcode-solution-30683ff85b40
*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            
            count += high - low;
        }
        
        return count;
    }
};