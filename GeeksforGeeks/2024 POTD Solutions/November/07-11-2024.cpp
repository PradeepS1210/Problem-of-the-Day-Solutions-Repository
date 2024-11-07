/*
Problem of the Day: Split array in three equal sum subarrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/split-array-in-three-equal-sum-subarrays-geeksforgeeks-solution-81de477527ba
*/

class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        if (totalSum % 3 != 0) {
            return {-1, -1};
        }
        
        int partSum = totalSum / 3;
        int n = arr.size();
        int currentSum = 0;
        int firstSplit = -1, secondSplit = -1;
        
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            
            if (currentSum == partSum && firstSplit == -1) {
                firstSplit = i;
            }
            else if (currentSum == 2 * partSum && firstSplit != -1) {
                secondSplit = i;
                break;
            }
        }
        
        if (firstSplit != -1 && secondSplit != -1) {
            return {firstSplit, secondSplit};
        }
        
        return {-1, -1};
    }
};