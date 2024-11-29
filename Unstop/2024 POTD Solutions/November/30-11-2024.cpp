/*
Problem of the Day: Frequent Traffic
Problem Description: https://medium.com/@pradeepsooryavanshee1210/frequent-traffic-unstop-solution-734757d77fea
*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN];
int ans = 0;

bool dfs(int curr) {
    vis[curr] = true;
    bool needsCar = false;

    for (auto& neighbor : adj[curr]) {
        int nextNode = neighbor.first;
        int weight = neighbor.second;

        if (vis[nextNode]) continue;

        if (weight == 0) {
            if (dfs(nextNode)) {
                needsCar = true;
            } else {
                needsCar = true;
                ans++;
            }
        } else {
            if (dfs(nextNode)) {
                needsCar = true;
            }
        }
    }

    return needsCar;
}

int main() {
    int n;
    cin >> n;

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}