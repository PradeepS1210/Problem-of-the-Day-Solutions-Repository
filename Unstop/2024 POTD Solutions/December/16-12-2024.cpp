/*
Problem of the Day: Bruno's Rabbits
Problem Description: https://medium.com/@pradeepsooryavanshee1210/brunos-rabbits-unstop-solution-576283466218
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> m;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < k) {
            if (m.find(a[i - 1]) == m.end()) {
                m[a[i - 1]] = min(i, n - i + 1);
            } else {
                m[a[i - 1]] = min(m[a[i - 1]], min(i, n - i + 1));
            }
        }
    }

    bool flag = false;
    int mini = 0;
    for (int i = 1; i < k; i++) {
        if (m.count(i) && m.count(k - i) && i != (k - i)) {
            if (!flag) {
                mini = max(m[i], m[k - i]);
                flag = true;
            } else {
                mini = min(mini, max(m[i], m[k - i]));
            }
        }
    }

    if (!flag) {
        cout << "-1" << endl;
    } else {
        cout << mini << endl;
    }

    return 0;
}