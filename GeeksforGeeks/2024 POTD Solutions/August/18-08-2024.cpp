/*
Asked in Facebook
Problem of the Day: Split an array into two equal Sum subarrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/split-an-array-into-two-equal-sum-subarrays-geeksforgeeks-solution-5bb23e855154
*/

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totalSum / 2;
        int runningSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            runningSum += arr[i];

            if (runningSum == halfSum)
            {
                return true;
            }
        }

        return false;
    }
};