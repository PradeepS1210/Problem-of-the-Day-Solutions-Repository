/*
Problem of the Day: Minimum number of deletions and insertions
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-number-of-deletions-and-insertions-geeksforgeeks-solution-8d72b0ab40e5
*/

class Solution
{
public:
    int minOperations(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];

        return (m - lcsLength) + (n - lcsLength);
    }
};