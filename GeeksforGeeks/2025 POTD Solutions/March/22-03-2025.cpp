/*
Problem of the Day: Stickler Thief II
Problem Description: https://www.geeksforgeeks.org/problems/house-robber-ii/1
*/

class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0, curr = 0;
        for (int i = start; i <= end; i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int robFirstToSecondLast = robLinear(arr, 0, n - 2);
        int robSecondToLast = robLinear(arr, 1, n - 1);

        return max(robFirstToSecondLast, robSecondToLast);
    }
};
