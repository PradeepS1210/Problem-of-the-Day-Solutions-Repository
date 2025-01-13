/*
Problem of the Day: Subset Maximization
Problem Description: https://unstop.com/code/practice/296904
*/

#include <bits/stdc++.h>
using namespace std;

int subMax(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    for (int i = 0; i < n; ++i) {
        int cur = arr[i];
        int prev = cur - 2;
        int sz = 0;

        if (mp.count(prev) && !mp[prev].empty()) {
            sz = mp[prev].top();
            mp[prev].pop();
        }

        sz += 1;

        if (!mp.count(cur)) {
            mp[cur] = priority_queue<int, vector<int>, greater<int>>();
        }
        mp[cur].push(sz);
    }

    int ans = n;
    for (auto& ent : mp) {
        if (!ent.second.empty()) {
            ans = min(ans, ent.second.top());
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = subMax(arr, n);
    cout << res << endl;
    return 0;
}
