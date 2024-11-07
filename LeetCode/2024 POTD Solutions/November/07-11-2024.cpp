/*
Problem of the Day: 2275. Largest Combination With Bitwise AND Greater Than Zero
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2275-largest-combination-with-bitwise-and-greater-than-zero-leetcode-solution-245ef0865ac6
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;
        vector<int> bitCount(24, 0);

        for (int num : candidates) {
            for (int i = 0; i < 24; ++i) {
                if (num & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }

        for (int count : bitCount) {
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};