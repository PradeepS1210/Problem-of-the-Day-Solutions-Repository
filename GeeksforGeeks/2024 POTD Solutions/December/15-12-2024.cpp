/*
Problem of the Day: Peak element
Problem Description: https://medium.com/@pradeepsooryavanshee1210/peak-element-geeksforgeeks-solutions-4749fc12ebe1
*/

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};