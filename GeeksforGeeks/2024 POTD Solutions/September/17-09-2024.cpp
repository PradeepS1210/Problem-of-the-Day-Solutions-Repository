/*
Asked in Microsoft, Adobe
Problem of the Day: Minimize the Heights II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimize-the-heights-ii-geeksforgeeks-solution-8de0f0c3c818
*/

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        sort(arr.begin(), arr.end());

        int diff = arr[n - 1] - arr[0];

        int smallest, largest;

        for (int i = 0; i < n - 1; i++)
        {
            smallest = min(arr[0] + k, arr[i + 1] - k);
            largest = max(arr[n - 1] - k, arr[i] + k);

            if (smallest >= 0)
            {
                diff = min(diff, largest - smallest);
            }
        }

        return diff;
    }
};
