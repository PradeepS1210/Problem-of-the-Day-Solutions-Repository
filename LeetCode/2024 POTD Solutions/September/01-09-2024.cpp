/*
Problem of the Day: 2022. Convert 1D Array Into 2D Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2022-convert-1d-array-into-2d-array-leetcode-solution-c6e74b8b94c0
*/

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != m * n)
        {
            return {};
        }

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < original.size(); i++)
        {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};