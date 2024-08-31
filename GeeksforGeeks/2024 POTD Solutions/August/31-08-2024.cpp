/*
Asked in Amazon, FactSet, Walmart
Problem of the Day: Sorted subsequence of size 3
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sorted-subsequence-of-size-3-geeksforgeeks-solution-0efb763a70b1
*/

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return {};

        int smaller[n];
        int larger[n];

        smaller[0] = -1;
        int min_index = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[min_index])
            {
                min_index = i;
                smaller[i] = -1;
            }
            else
            {
                smaller[i] = min_index;
            }
        }

        larger[n - 1] = -1;
        int max_index = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[max_index])
            {
                max_index = i;
                larger[i] = -1;
            }
            else
            {
                larger[i] = max_index;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (smaller[i] != -1 && larger[i] != -1)
            {
                return {arr[smaller[i]], arr[i], arr[larger[i]]};
            }
        }

        return {};
    }
};