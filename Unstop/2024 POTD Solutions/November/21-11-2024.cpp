/*
Asked in Microsoft, Amazon, Citadel, Atlassian, Capgemini
Problem of the Day: Different Occurrences
Problem Description: https://medium.com/@pradeepsooryavanshee1210/different-occurrences-unstop-solution-d6e81153e0de
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubsequences(const string& S, const string& query) {
    int n = S.length();
    int m = query.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i - 1] == query[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    string S, query;
    cin >> S >> query;

    int result = countSubsequences(S, query);
    cout << result << endl;

    return 0;
}