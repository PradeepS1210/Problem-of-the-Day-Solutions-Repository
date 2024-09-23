/*
Problem of the Day: 2707. Extra Characters in a String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2707-extra-characters-in-a-string-leetcode-solution-63b2226db7b1
*/

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + 1;

            for (int j = i; j >= 1; --j)
            {
                string substring = s.substr(j - 1, i - j + 1);
                if (dict.find(substring) != dict.end())
                {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }

        return dp[n];
    }
};