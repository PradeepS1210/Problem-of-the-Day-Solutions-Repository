/*
Problem of the Day: Non-overlapping Intervals
Problem Description: https://medium.com/@pradeepsooryavanshee1210/non-overlapping-intervals-geeksforgeeks-solution-0f7075b16993
*/

class Solution {
public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int prev_end = INT_MIN;

        for (const auto &interval : intervals) {
            if (interval[0] >= prev_end) {
                prev_end = interval[1];
            } else {
                count++;
            }
        }

        return count;
    }
};