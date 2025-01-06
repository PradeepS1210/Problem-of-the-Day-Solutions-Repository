/*
Problem of the Day: Sum Pair closest to target
Problem Description: https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1
*/

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if (arr.size() < 2) return {};

        sort(arr.begin(), arr.end());

        int left = 0, right = arr.size() - 1;
        int closestSum = INT_MAX;
        int maxDiff = INT_MIN;
        vector<int> result;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (abs(target - sum) < abs(target - closestSum) || 
                (abs(target - sum) == abs(target - closestSum) && (arr[right] - arr[left] > maxDiff))) {
                closestSum = sum;
                maxDiff = arr[right] - arr[left];
                result = {arr[left], arr[right]};
            }

            if (sum < target) {
                ++left;
            } else if (sum > target) {
                --right;
            } else {
                return result;
            }
        }

        return result;
    }
};