/*
Asked in Zoho, Amazon, Microsoft, Ola Cabs, Walmart, Google, InMobi, United Health Group
Problem of the Day: Wildcard Pattern Matching
Problem Description: https://medium.com/@pradeepsooryavanshee1210/wildcard-pattern-matching-geeksforgeeks-solution-e48d1e10fc22
*/

class Solution
{
public:
    int wildCard(string pattern, string str)
    {
        int n = pattern.size();
        int m = str.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            if (pattern[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0];
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (pattern[i - 1] == '?' || pattern[i - 1] == str[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m] ? 1 : 0;
    }
};
