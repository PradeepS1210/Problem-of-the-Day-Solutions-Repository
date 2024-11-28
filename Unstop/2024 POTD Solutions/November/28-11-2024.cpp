/*
Problem of the Day: Triple Subsequence
problem Description: https://medium.com/@pradeepsooryavanshee1210/triple-subsequence-unstop-solution-bbb3a029f058
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] * 3 == arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr) << endl;

    return 0;
}