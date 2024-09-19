/*
Problem of the Day: Palindrome Game
Problem Description: https://medium.com/@pradeepsooryavanshee1210/palindrome-game-unstop-solution-3d0853e5702a
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string &str1, string &str2)
{
    int n = str1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int minInsertionsToPalindrome(string &str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    int lcsLength = longestCommonSubsequence(str, revStr);

    return str.length() - lcsLength;
}

int main()
{
    string str;
    cin >> str;

    int result = minInsertionsToPalindrome(str);
    cout << result << endl;

    return 0;
}