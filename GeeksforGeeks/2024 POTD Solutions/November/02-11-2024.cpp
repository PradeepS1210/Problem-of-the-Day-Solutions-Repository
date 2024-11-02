/*
Problem of the Day: Kth distance
Problem Description: https://medium.com/@pradeepsooryavanshee1210/kth-distance-geeksforgeeks-solution-7703fc26d3d8
*/

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;

        for (int i = 0; i < arr.size(); i++) {
            if (window.find(arr[i]) != window.end()) {
                return true;
            }
            
            window.insert(arr[i]);

            if (i >= k) {
                window.erase(arr[i - k]);
            }
        }

        return false;
    }
};