/*
Problem of the Day: Not a subset sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/not-a-subset-sum-geeksforgeeks-solution-156b9ec96a94
*/

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        long long res = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > res)
                return res;
            res += arr[i];
        }
        return res;
    }
};