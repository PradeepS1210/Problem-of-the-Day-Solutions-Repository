/*
Asked in Amazon, Microsoft
Problem of the Day: Max Circular Subarray Sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/max-circular-subarray-sum-geeksforgeeks-solution-38bc8574fd83
*/

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();

        int max_kadane = kadane(arr);

        int total_sum = 0;
        for (int i = 0; i < n; ++i) {
            total_sum += arr[i];
            arr[i] = -arr[i];
        }

        int min_kadane = kadane(arr);

        int circular_sum = total_sum + min_kadane;

        if (circular_sum == 0) {
            return max_kadane;
        }

        return max(max_kadane, circular_sum);
    }

private:
    int kadane(vector<int>& arr) {
        int max_sum = arr[0], current_sum = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            current_sum = max(arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};