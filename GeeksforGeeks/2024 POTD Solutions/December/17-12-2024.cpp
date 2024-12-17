/*
Problem of the Day: Aggressive Cows
Problem Description: https://medium.com/@pradeepsooryavanshee1210/aggressive-cows-geeksforgeeks-solution-72c5519747c1
*/

class Solution {
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int start = 1, end, mid, ans = 0, n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        end = stalls[n - 1] - stalls[0];
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            int count = 1, position = stalls[0];
            for (int i = 1; i < n; i++) {
                if (position + mid <= stalls[i]) {
                    count++;
                    position = stalls[i];
                }
            }
            
            if (count < k) {
                end = mid - 1;
            } else {
                ans = mid;
                start = mid + 1;
            }
        }
        
        return ans;
    }
};