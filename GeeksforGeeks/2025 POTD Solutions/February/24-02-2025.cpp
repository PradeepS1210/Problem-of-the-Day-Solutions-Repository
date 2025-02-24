/*
Problem of the Day: Stock span problem
Problem Description: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n, 1);
        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; ++i) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            span[i] = (s.empty()) ? (i + 1) : (i - s.top());
            s.push(i);
        }
        return span;
    }
};
