/*
Problem of the Day: Speed Ticket
Problem Decription: https://medium.com/@pradeepsooryavanshee1210/speed-ticket-unstop-solution-d809e6f721a3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long cnt = 0;

    int i = 0, j = 0;
    while (i < n) {
        if (j < i) {
            j = i;
        } else if (j >= n) {
            break;
        }

        if (a[j] - a[i] >= k) {
            cnt += (n - j);
            i++;
        } else {
            j++;
        }
    }

    if (cnt >= x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t > 0) {
        solve();
        t--;
    }
    
    return 0;
}