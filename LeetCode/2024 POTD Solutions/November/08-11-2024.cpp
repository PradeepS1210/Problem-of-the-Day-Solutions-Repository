/*
Problem of the Day: 1829. Maximum XOR for Each Query
Problem Desription: https://medium.com/@pradeepsooryavanshee1210/1829-maximum-xor-for-each-query-leetcode-solution-049952a1285b
*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxXor = (1 << maximumBit) - 1;
        
        int xor_all = 0;
        for (int num : nums) {
            xor_all ^= num;
        }
        
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = xor_all ^ maxXor;
            xor_all ^= nums[n - 1 - i];
        }
        
        return answer;
    }
};