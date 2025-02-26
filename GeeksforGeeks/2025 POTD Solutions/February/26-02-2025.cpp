/*
Problem of the Day: Maximum of minimum for every window size
Problem Description: https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
*/

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        vector<int> left(n), right(n);
        
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        vector<int> ans(n+1, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        
        for (int i = n-1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        for (int i = 1; i <= n; i++) {
            result[i-1] = ans[i];
        }
        
        return result;
    }
};
