/*
Problem of the Day: Modify the Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/modify-the-array-geeksforgeeks-solution-08fdde3099d8
*/

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }
        
        int index = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }
        
        while (index < n) {
            arr[index++] = 0;
        }
        
        return arr;
    }
};
