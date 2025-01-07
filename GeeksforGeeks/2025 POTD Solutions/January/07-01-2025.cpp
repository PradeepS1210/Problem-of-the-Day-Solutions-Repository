/*
Problem of the Day: Pair with given sum in a sorted array
Problem Description: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : arr) {
            freq[num]++;
        }

        for (int num : arr) {
            int complement = target - num;
            if (freq[complement] > 0) {
                if (complement == num) {
                    count += freq[num] - 1;
                } else {
                    count += freq[complement];
                }
            }
        }

        return count / 2;
    }
};