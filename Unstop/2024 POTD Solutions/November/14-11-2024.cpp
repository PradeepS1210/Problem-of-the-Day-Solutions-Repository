/*
Problem of the Day: Optimized Laundry Scheduling
Problem Description: https://medium.com/@pradeepsooryavanshee1210/optimized-laundry-scheduling-unstop-solution-9e7d0123f3c5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solve(int K, int N, int M, vector<int>& W, vector<int>& D) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> washed;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dried;

    for (int i = 0; i < N; ++i) {
        washed.push({W[i], i});
    }
    for (int i = 0; i < M; ++i) {
        dried.push({D[i], i});
    }

    vector<int> endingTimeWashed(K, 0);
    vector<int> endingTimeDried(K, 0);

    for (int i = 0; i < K; ++i) {
        auto p = washed.top();
        washed.pop();
        endingTimeWashed[i] = p.first;
        washed.push({p.first + W[p.second], p.second});
    }

    for (int i = 0; i < K; ++i) {
        auto p = dried.top();
        dried.pop();
        endingTimeDried[i] = p.first;
        dried.push({p.first + D[p.second], p.second});
    }

    sort(endingTimeWashed.begin(), endingTimeWashed.end());
    sort(endingTimeDried.rbegin(), endingTimeDried.rend());

    int ans = 0;
    for (int i = 0; i < K; ++i) {
        ans = max(ans, endingTimeWashed[i] + endingTimeDried[i]);
    }

    return ans;
}

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    vector<int> W(N), D(M);
    for (int i = 0; i < N; ++i) cin >> W[i];
    for (int i = 0; i < M; ++i) cin >> D[i];

    int ans = solve(K, N, M, W, D);
    cout << ans << endl;

    return 0;
}