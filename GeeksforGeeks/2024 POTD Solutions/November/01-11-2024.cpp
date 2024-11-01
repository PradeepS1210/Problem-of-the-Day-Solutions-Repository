/*
Problem of the Day: Swap and Maximize
Problem Description: https://medium.com/@pradeepsooryavanshee1210/swap-and-maximize-geeksforgeeks-solution-c5c6f5069587
*/

class Solution {
public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> reorderedArr;
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            if (left == right) {
                reorderedArr.push_back(arr[left]);
            } else {
                reorderedArr.push_back(arr[left]);
                reorderedArr.push_back(arr[right]);
            }
            left++;
            right--;
        }

        long long maxSum = 0;
        int n = reorderedArr.size();
        for (int i = 0; i < n; i++) {
            maxSum += abs(reorderedArr[i] - reorderedArr[(i + 1) % n]);
        }

        return maxSum;
    }
};