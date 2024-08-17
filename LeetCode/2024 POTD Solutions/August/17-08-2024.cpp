/*
Problem of the Day: 1937. Maximum Number of Points with Cost
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1937-maximum-number-of-points-with-cost-leetcode-solution-e9db5e1e497c
*/

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();

        vector<long long> dp(n, 0);

        for (int j = 0; j < n; ++j)
        {
            dp[j] = points[0][j];
        }

        for (int i = 1; i < m; ++i)
        {
            vector<long long> left(n, 0), right(n, 0), new_dp(n, 0);

            left[0] = dp[0];
            for (int j = 1; j < n; ++j)
            {
                left[j] = max(left[j - 1], dp[j] + j);
            }

            right[n - 1] = dp[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j)
            {
                right[j] = max(right[j + 1], dp[j] - j);
            }

            for (int j = 0; j < n; ++j)
            {
                new_dp[j] = points[i][j] + max(left[j] - j, right[j] + j);
            }

            dp = new_dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};