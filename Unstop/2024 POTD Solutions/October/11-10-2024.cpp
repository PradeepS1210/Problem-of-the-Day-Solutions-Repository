/*
Problem of the Day: Davy Back Fight
Problem Description: https://medium.com/@pradeepsooryavanshee1210/davy-back-fight-unstop-solution-5813e5c0861c
*/

#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, strength;

    DSU(int n, const vector<int>& strengths) {
        parent.resize(n + 1);
        strength = strengths;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return;
        }

        if (strength[rootX] > strength[rootY]) {
            parent[rootY] = rootX;
        } else if (strength[rootX] < strength[rootY]) {
            parent[rootX] = rootY;
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> strengths(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> strengths[i];
    }

    DSU dsu(N, strengths);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int X, Y;
            cin >> X >> Y;
            if (dsu.find(X) == dsu.find(Y)) {
                cout << -1 << endl;
            } else {
                dsu.unite(X, Y);
            }
        } else if (type == 2) {
            int X;
            cin >> X;
            cout << dsu.find(X) << endl;
        }
    }

    return 0;
}