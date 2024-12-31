/*
Problem of the Day: Longest Consecutive Subsequence
Problem Description: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(), arr.end());
        int longestStreak = 0;

        for (int num : nums) {
            if (nums.find(num - 1) == nums.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (nums.find(currentNum + 1) != nums.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};