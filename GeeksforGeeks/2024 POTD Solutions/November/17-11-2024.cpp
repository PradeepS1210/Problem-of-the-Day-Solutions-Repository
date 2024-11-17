/*
Asked in: Bloomberg, Facebook, TCS, Adobe, Google, Infosys, Capgemini, Morgan Stanley, Amazon, Microsoft, Apple, Yahoo, PayPal, Uber
Problem of the Day: Reverse an Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/reverse-an-array-geeksforgeeks-solution-bb12aa32a378
*/

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};