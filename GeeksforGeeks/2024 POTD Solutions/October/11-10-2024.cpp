/*
Problem of the Day: Reorganize The Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/reorganize-the-array-geeksforgeeks-solution-99791de19a1d
*/

class Solution {
public:
    vector<int> rearrange(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            while (arr[i] != -1 && arr[i] != i) {
                int correctIndex = arr[i];
                
                if (arr[correctIndex] == correctIndex) break;
                
                swap(arr[i], arr[correctIndex]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != i) {
                arr[i] = -1;
            }
        }
        
        return arr;
    }
};