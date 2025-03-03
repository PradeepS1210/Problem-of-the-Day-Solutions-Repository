/*
Problem of the Day: Vowel Sequence Encryption
Problem Description: https://unstop.com/code/practice/537417
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int N;
    long long P;
    cin >> N >> P;

    vector<vector<int>> transitions = {
        {1, 1, 0, 0, 0}, // transitions from 'a'
        {0, 0, 1, 0, 1}, // transitions from 'e'
        {0, 0, 0, 1, 1}, // transitions from 'i'
        {1, 1, 0, 0, 0}, // transitions from 'o'
        {0, 1, 0, 0, 1}  // transitions from 'u'
    };

    vector<vector<long long>> dp(N, vector<long long>(5, 0));
    for (int i = 0; i < 5; ++i)
        dp[0][i] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                if (transitions[j][k])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % P;
                }
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < 5; ++i)
    {
        result = (result + dp[N - 1][i]) % P;
    }

    // Convert to octal
    string octal;
    while (result > 0)
    {
        octal = to_string(result % 8) + octal;
        result /= 8;
    }

    if (octal.empty())
        octal = "0";
    cout << octal << endl;

    return 0;
}