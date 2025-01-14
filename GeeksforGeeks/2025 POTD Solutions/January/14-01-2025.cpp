/*
Problem of the Day: Equilibrium Point
Problem Description: https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
*/

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
        }

        int leftSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum -= arr[i];
            
            if (leftSum == totalSum) {
                return i;
            }

            leftSum += arr[i];
        }

        return -1;
    }
};