/*
Asked in SAP Labs
Problem of the Day:Maximize Array Value After Rearrangement
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximize-array-value-after-rearrangement-geeksforgeeks-solution-da14b9835c0f
*/

class Solution
{
public:
    int Maximize(std::vector<int> &arr)
    {
        const int MOD = 1000000007;
        int n = arr.size();

        std::sort(arr.begin(), arr.end());

        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result = (result + (static_cast<long long>(arr[i]) * i) % MOD) % MOD;
        }

        return static_cast<int>(result);
    }
};