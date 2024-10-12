/*
Problem of the Day: Two Smallests in Every Subarray
Problem Description: https://medium.com/@pradeepsooryavanshee1210/two-smallests-in-every-subarray-geeksforgeeks-solution-e2e0d2084707
*/

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        if (arr.size() < 2) {
            return -1;
        }
        
        int maxSum = arr[0] + arr[1];

        for (int i = 1; i < arr.size() - 1; i++) {
            int currentSum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
