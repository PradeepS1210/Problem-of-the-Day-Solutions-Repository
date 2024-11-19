/*
Problem of the Day: Next Permutation
Problem Description: https://medium.com/@pradeepsooryavanshee1210/next-permutation-geeksforgeeks-solution-b0f77ca137e9
*/

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(), i = n - 2;

        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (arr[j] <= arr[i]) {
                j--;
            }
            swap(arr[i], arr[j]);
        }

        reverse(arr.begin() + i + 1, arr.end());
    }
};