/*
Problem of the Day: Kadane’s Algorithm
Problem Description: https://medium.com/@pradeepsooryavanshee1210/kadanes-algorithm-geeksforgeeks-solution-cfc5196d6975
*/

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (int num : arr) {
            currentSum = max(num, currentSum + num);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};