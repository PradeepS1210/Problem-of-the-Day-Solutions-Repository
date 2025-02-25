/*
Problem of the Day: Histogram Max Rectangular Area
Problem Description: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
*/

class Solution {
public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        int max_area = 0;
        int tp;
        int area_with_top;

        int i = 0;
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]) {
                s.push(i++);
            } else {
                tp = s.top();
                s.pop();
                area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, area_with_top);
            }
        }

        while (!s.empty()) {
            tp = s.top();
            s.pop();
            area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area_with_top);
        }

        return max_area;
    }
};
