/*
Problem of the Day: Valentines Day
Problem Description: https://medium.com/@pradeepsooryavanshee1210/valentines-day-unstop-solution-problem-of-the-day-130be28c7ba3
*/

#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, vector<int> &coins, int sum)
{
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= sum; j++)
        {
            if (dp[j - coins[i]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}

int main()
{
    int n, sum;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cin >> sum;

    cout << minCoins(n, coins, sum) << endl;

    return 0;
}