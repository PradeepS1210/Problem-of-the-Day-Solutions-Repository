/*
Problem of the Day: Kth Missing Positive Number in a Sorted Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/kth-missing-positive-number-in-a-sorted-array-geeksforgeeks-solution-536ab0f2bdd2
*/

class Solution {
public:
    int kthMissing(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1, ans = arr.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] - (mid + 1) >= k) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans + k;
    }
};