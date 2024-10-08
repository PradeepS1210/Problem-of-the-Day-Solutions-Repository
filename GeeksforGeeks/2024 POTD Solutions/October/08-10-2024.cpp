/*
problem of the Day: Largest Pair Sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/largest-pair-sum-geeksforgeeks-solution-095a10c850c2
*/

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        
        if(n < 2) return 0;
        
        int first_max = INT32_MIN;
        int second_max = INT32_MIN;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > first_max) {
                second_max = first_max;
                first_max = arr[i];
            }
            else if(arr[i] > second_max && arr[i] != first_max) {
                second_max = arr[i];
            }
            else if(arr[i] > second_max && arr[i] == first_max) {
                second_max = arr[i];
            }
        }
        
        if(second_max == INT32_MIN) {
            second_max = first_max;
        }
        
        return first_max + second_max;
    }
};
