/*
Problem of the Day: Stickler Thief
Problem Description: https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
*/

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = 0;
        int prev1 = arr[0];
        
        for (int i = 1; i < n; i++) {
            int curr = max(prev1, arr[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
