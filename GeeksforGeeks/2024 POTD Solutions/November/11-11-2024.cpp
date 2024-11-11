/*
Problem of the Day: Make array elements unique
Problem Description: https://medium.com/@pradeepsooryavanshee1210/make-array-elements-unique-geeksforgeeks-solution-924868f2ed8d
*/

class Solution {
public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int increments = 0;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i - 1]) {
                int newVal = arr[i - 1] + 1;
                increments += newVal - arr[i];
                arr[i] = newVal;
            }
        }
        
        return increments;
    }
};