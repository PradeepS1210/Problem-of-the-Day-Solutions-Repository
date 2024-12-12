/*
Problem of the Day: Number of occurrence
Problem Description: https://medium.com/@pradeepsooryavanshee1210/number-of-occurrence-geeksforgeeks-solutions-19b2a8cc3887
*/

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        if (first == arr.size() || arr[first] != target) {
            return 0;
        }

        int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;

        return last - first + 1;
    }
};