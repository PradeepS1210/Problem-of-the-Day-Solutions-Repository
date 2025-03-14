/*
Problem of the Day: Minimum Time to Complete All Tasks
Problem Description: https://unstop.com/code/practice/541262
*/

#include <bits/stdc++.h>
using namespace std;

int minimumTimeToCompleteTasks(int N, vector<int>& time, int M, vector<pair<int, int>>& dependencies) {
    vector<int> inDegree(N, 0);
    vector<vector<int>> adj(N);
    vector<int> completionTime(N, 0);
    
    for (auto& dep : dependencies) {
        int a = dep.first, b = dep.second;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            completionTime[i] = time[i];
        }
    }

    int result = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        result = max(result, completionTime[current]);

        for (int neighbor : adj[current]) {
            inDegree[neighbor]--;
            completionTime[neighbor] = max(completionTime[neighbor], completionTime[current] + time[neighbor]);

            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }
    cin >> M;
    vector<pair<int, int>> dependencies(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dependencies[i] = {a, b};
    }

    cout << minimumTimeToCompleteTasks(N, time, M, dependencies) << endl;

    return 0;
}
