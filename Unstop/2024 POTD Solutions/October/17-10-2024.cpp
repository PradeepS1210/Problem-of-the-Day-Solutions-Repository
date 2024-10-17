/*
Problem of the Day: Delivery
Problem Description: https://medium.com/@pradeepsooryavanshee1210/delivery-unstop-solution-aad91812cf6c
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int component[MAXN];

void dfs(int node, int comp) {
    component[node] = comp;
    for (int neighbor : adj[node]) {
        if (component[neighbor] == -1) {
            dfs(neighbor, comp);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    memset(component, -1, sizeof(component));

    int comp = 0;
    for (int i = 0; i < N; i++) {
        if (component[i] == -1) {
            dfs(i, comp);
            comp++;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        if (component[X] == component[Y]) {
            cout << "YO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}