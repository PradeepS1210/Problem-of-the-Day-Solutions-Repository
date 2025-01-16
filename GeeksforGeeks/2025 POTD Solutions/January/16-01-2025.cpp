/*
Problem of the Day: Largest subarray of 0's and 1's
Problem Description: https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
*/

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> hash_map;
        int max_len = 0, sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            sum += (arr[i] == 0) ? -1 : 1;

            if (sum == 0)
                max_len = i + 1;

            if (hash_map.find(sum) != hash_map.end()) {
                max_len = max(max_len, i - hash_map[sum]);
            } else {
                hash_map[sum] = i;
            }
        }

        return max_len;
    }
};