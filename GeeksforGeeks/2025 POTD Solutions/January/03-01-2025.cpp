/*
Problem of the Day: Count Subarrays with given XOR
Problem Description: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> xorFreq;
        long count = 0;
        int xorSum = 0;

        for (int num : arr) {
            xorSum ^= num;

            if (xorSum == k) {
                count++;
            }

            if (xorFreq.find(xorSum ^ k) != xorFreq.end()) {
                count += xorFreq[xorSum ^ k];
            }

            xorFreq[xorSum]++;
        }

        return count;
    }
};