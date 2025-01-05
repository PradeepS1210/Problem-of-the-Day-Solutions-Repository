/*
Problem of the Day: Count Pairs whose sum is less than target
Problem Description: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        
        int start = 0, end = arr.size()-1;
        int count = 0;
        
        while(start < end) {
            if(arr[start] + arr[end] < target) {
                count += (end - start);
                start++;
            }
            else
                end--;
        }
        
        return count;
    }
};