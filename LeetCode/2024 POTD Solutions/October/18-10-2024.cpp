/*
Problem of the Day: 2044. Count Number of Maximum Bitwise-OR Subsets
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2044-count-number-of-maximum-bitwise-or-subsets-leetcode-solution-61bfdd15985b
*/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0, count = 0;
        
        for (int num : nums) {
            max_or |= num;
        }
        
        int n = nums.size();
        int total_subsets = 1 << n;
        
        for (int mask = 0; mask < total_subsets; ++mask) {
            int subset_or = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset_or |= nums[i];
                }
            }
            
            if (subset_or == max_or) {
                count++;
            }
        }
        
        return count;
    }
};
