/*
Problem of the Day: Cards
Problem Description: https://medium.com/@pradeepsooryavanshee1210/unstop-cards-problem-solution-problem-of-the-day-0784ac250810
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i] >> B[i];
    }

    vector<vector<int>> dp(N, vector<int>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        if (A[i] != A[i - 1])
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
        }
        if (A[i] != B[i - 1])
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        }
        if (B[i] != A[i - 1])
        {
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        }
        if (B[i] != B[i - 1])
        {
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
        }
    }

    int result = (dp[N - 1][0] + dp[N - 1][1]) % MOD;
    cout << result << endl;

    return 0;
}