/*
Asked in Google, Goldman Sachs, Facebook
Problem of the Day: Pass
Problem Description: https://medium.com/@pradeepsooryavanshee1210/pass-unstop-potd-solution-570dfd4238f2
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int d = 1; d <= 9; d++)
    {
        dp[1][d] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int d = 1; d <= 9; d++)
        {
            dp[i][d] = dp[i - 1][d];
            if (d > 1)
            {
                dp[i][d] = (dp[i][d] + dp[i - 1][d - 1]) % MOD;
            }
            if (d < 9)
            {
                dp[i][d] = (dp[i][d] + dp[i - 1][d + 1]) % MOD;
            }
        }
    }

    int result = 0;
    for (int d = 1; d <= 9; d++)
    {
        result = (result + dp[N][d]) % MOD;
    }

    cout << result << endl;
    return 0;
}