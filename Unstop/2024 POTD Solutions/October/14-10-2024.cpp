/*
Problem of the Day: Message Passing
Problem Description: https://medium.com/@pradeepsooryavanshee1210/message-passing-unstop-solution-5335d45b0a02
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    if (n <= 2) {
        return n;
    }

    int max_len = 2;
    vector<int> dp(n, 2);

    for (int j = n - 2; j >= 0; --j) {
        int i = j - 1;
        int k = j + 1;

        while (i >= 0 && k < n) {
            if (a[i] + a[k] == 2 * a[j]) {
                dp[j] = max(dp[k] + 1, dp[j]);
                max_len = max(max_len, dp[j]);
                --i;
                ++k;
            } else if (a[i] + a[k] < 2 * a[j]) {
                ++k;
            } else {
                --i;
            }
        }
    }

    return max_len;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    cout << solve(vec) << endl;
    return 0;
}