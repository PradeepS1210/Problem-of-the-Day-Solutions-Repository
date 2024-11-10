/*
Problem of the Day: Codegram
Problem Description: https://medium.com/@pradeepsooryavanshee1210/codegram-unstop-solution-9ceac446ffdc
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 1; s * (s - 1) / 2 <= i; ++s) {
            int p = (s * (s - 1)) / 2;
            dp[i] = min(dp[i], dp[i - p] + s);
        }
    }

    long long resultPairs = (long long) dp[n] * (dp[n] - 1) / 2 - n;
    cout << dp[n] << " " << resultPairs << endl;
}

int main() {
    solve();
    return 0;
}