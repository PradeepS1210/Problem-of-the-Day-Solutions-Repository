/*
Problem of the Day: Kadane's Algorithm
Problem Description: https://medium.com/@pradeepsooryavanshee1210/kadanes-algorithm-geeksforgeeks-solution-07018556c783
*/

class Solution
{
public:
    long long maxSubarraySum(vector<int> &arr)
    {
        long long current_sum = 0;
        long long max_sum = LLONG_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            current_sum = max((long long)arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
