/*
Problem of the Day: 1590. Make Sum Divisible by P
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1590-make-sum-divisible-by-p-leetcode-solution-a6e038130d24
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(auto num : nums) {
            total += num;
        }
        
        if(total % p == 0) return 0;
        
        long long remainder = total % p;
        
        unordered_map<long long, int> modMap;
        modMap[0] = -1;
        
        long long prefix = 0;
        int minLength = INT32_MAX;
        
        for(int i = 0; i < nums.size(); ++i){
            prefix = (prefix + nums[i] % p) % p;
            
            long long target = (prefix - remainder + p) % p;
            
            if(modMap.find(target) != modMap.end()){
                int length = i - modMap[target];
                if(length < minLength){
                    minLength = length;
                }
            }
            
            modMap[prefix] = i;
        }
        
        return minLength == INT32_MAX || minLength == nums.size() ? -1 : minLength;
    }
};