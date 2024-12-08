/*
Problem of the Day: Overlapping Intervals
Problem Description: https://medium.com/@pradeepsooryavanshee1210/overlapping-intervals-geeksforgeeks-solution-974e17d9c01c
*/

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) return {};
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> merged;
        
        vector<int> current = arr[0];
        
        for (const auto& interval : arr) {
            if (interval[0] <= current[1]) {
                current[1] = max(current[1], interval[1]);
            } else {
                merged.push_back(current);
                current = interval;
            }
        }
        
        merged.push_back(current);
        
        return merged;
    }
};