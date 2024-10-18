/*
Problem of the Day: Single Number
Ptoblem Description: https://medium.com/@pradeepsooryavanshee1210/single-number-geeksforgeeks-solution-c33c20a83ab9
*/

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }
};
