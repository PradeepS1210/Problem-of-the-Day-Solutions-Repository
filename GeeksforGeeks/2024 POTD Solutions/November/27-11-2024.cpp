/*
Problem of the Day: Smallest Positive Missing Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/smallest-positive-missing-number-geeksforgeeks-solution-ff9079375574
*/

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        int size = n - j;
        vector<int> posArr(arr.begin() + j, arr.end());

        for (int i = 0; i < size; i++) {
            int val = abs(posArr[i]);
            if (val <= size && posArr[val - 1] > 0) {
                posArr[val - 1] = -posArr[val - 1];
            }
        }

        for (int i = 0; i < size; i++) {
            if (posArr[i] > 0) {
                return i + 1;
            }
        }

        return size + 1;
    }
};