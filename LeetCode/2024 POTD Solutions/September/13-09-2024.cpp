/*
Problem of the Day: 1310. XOR Queries of a Subarray
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1310-xor-queries-of-a-subarray-leetcode-solution-286691803cac
*/

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();

        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        vector<int> result;
        for (const auto &query : queries)
        {
            int left = query[0];
            int right = query[1];

            if (left == 0)
            {
                result.push_back(prefix[right]);
            }
            else
            {
                result.push_back(prefix[right] ^ prefix[left - 1]);
            }
        }

        return result;
    }
};