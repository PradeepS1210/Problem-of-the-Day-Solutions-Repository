/*
Problem of the Day: Move All Zeroes to End
Problem Description: https://medium.com/@pradeepsooryavanshee1210/move-all-zeroes-to-end-geeksforgeeks-solution-a3ecc4715810
*/

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int nonZeroIndex = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }
        
        while (nonZeroIndex < n) {
            arr[nonZeroIndex++] = 0;
        }
    }
};