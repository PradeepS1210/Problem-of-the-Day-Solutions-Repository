/*
Problem of the Day: 2501. Longest Square Streak in an Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2501-longest-square-streak-in-an-array-leetcode-solution-6bc7a1a35119
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int maxStreak = 0;
        
        for (int num : nums) {
            long long current = num;
            int streakLength = 0;
            
            while (numSet.count(current)) {
                streakLength++;
                current = current * current;
                if (current > 1e5) break;
            }
            
            maxStreak = max(maxStreak, streakLength);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
};
