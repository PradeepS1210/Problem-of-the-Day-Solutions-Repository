/*
Problem of the Day: 664. Strange Printer
Problem Description: https://medium.com/@pradeepsooryavanshee1210/664-strange-printer-leetcode-solution-089d47b2ea58
*/

class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k <= j; k++)
                {
                    if (s[k] == s[i])
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};