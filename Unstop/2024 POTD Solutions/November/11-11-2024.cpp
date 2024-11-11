/*
Problem of the Day: Helping Mike
Problem Description: https://medium.com/@pradeepsooryavanshee1210/helping-mike-unstop-solution-0feeb73998b9
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> values(n);
    vector<long long> queries(m);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    sort(values.begin(), values.end());

    vector<long long> prefixSum(n);
    prefixSum[0] = values[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + values[i];
    }

    for (int i = 0; i < m; i++) {
        long long q = queries[i];

        auto pos = lower_bound(values.begin(), values.end(), q) - values.begin();

        long long score = 0;

        if (pos > 0) {
            score += q * pos - prefixSum[pos - 1];
        }

        if (pos < n) {
            score += (prefixSum[n - 1] - (pos > 0 ? prefixSum[pos - 1] : 0)) - q * (n - pos);
        }

        cout << score << " ";
    }

    return 0;
}