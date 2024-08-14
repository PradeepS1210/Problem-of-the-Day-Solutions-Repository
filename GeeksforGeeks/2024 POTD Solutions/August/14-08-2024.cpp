/*
Asked in Morgan Stanley, Amazon, and Microsoft
Problem of the Day: Longest Common Substring
Problem Description: https://medium.com/@pradeepsooryavanshee1210/amazon-microsoft-interview-question-longest-common-substring-geeksforgeeks-solution-5da3909bacba
*/

class Solution
{
public:
    int longestCommonSubstr(std::string str1, std::string str2)
    {
        int n = str1.size();
        int m = str2.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        int maxLength = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = std::max(maxLength, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLength;
    }
};