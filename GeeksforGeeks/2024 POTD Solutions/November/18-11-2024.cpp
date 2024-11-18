/*
Problem of the Day: Rotate Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/rotate-array-geeksforgeeks-solution-502081830239
*/

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        if (d == 0) return;
        
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};