/*
Problem of the Day: Number of pairs
Problem Description: https://medium.com/@pradeepsooryavanshee1210/number-of-pairs-geeksforgeeks-solution-fdcff3b05f5d
*/

class Solution
{
public:
    long long countPairs(vector<int> &arr, vector<int> &brr)
    {
        long long totalPairs = 0;
        vector<int> count(1005, 0);
        int m = brr.size();

        for (int y : brr)
        {
            count[y]++;
        }

        sort(brr.begin(), brr.end());

        for (int x : arr)
        {
            if (x == 0)
                continue;

            if (x == 1)
            {
                continue;
            }

            int idx = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
            totalPairs += m - idx;

            totalPairs += count[1];

            if (x == 2)
            {
                totalPairs -= (count[3] + count[4]);
            }

            if (x == 3)
            {
                totalPairs += count[2];
            }
        }

        return totalPairs;
    }
};