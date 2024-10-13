/*
Problem of the Day: 632. Smallest Range Covering Elements from K Lists
Problem Description: https://medium.com/@pradeepsooryavanshee1210/632-smallest-range-covering-elements-from-k-lists-leetcode-solution-2ca4b51fd8fd
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int minRange = INT_MAX;
        int start = 0, end = 0;
        int currentMax = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        while (minHeap.size() == nums.size()) {
            vector<int> top = minHeap.top();
            minHeap.pop();
            int currentMin = top[0], row = top[1], idx = top[2];

            if (currentMax - currentMin < minRange) {
                minRange = currentMax - currentMin;
                start = currentMin;
                end = currentMax;
            }

            if (idx + 1 < nums[row].size()) {
                minHeap.push({nums[row][idx + 1], row, idx + 1});
                currentMax = max(currentMax, nums[row][idx + 1]);
            } else {
                break;
            }
        }

        return {start, end};
    }
};