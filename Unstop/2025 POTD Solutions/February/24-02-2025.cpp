/*
Problem of the Day: Maximum Absolute difference of leaf nodes
Problem Description: https://unstop.com/code/practice/262518
*/

#include <bits/stdc++.h>
using namespace std;

void findLeafNodes(vector<int>& nodes, int start, int end, vector<int>& leaves) {
    if (start > end) return;
    if (start == end) {
        leaves.push_back(nodes[start]);
        return;
    }
    int mid = (start + end + 1) / 2;
    findLeafNodes(nodes, start + 1, mid, leaves);
    findLeafNodes(nodes, mid + 1, end, leaves);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int levels;
        cin >> levels;
        int n = (1 << levels) - 1;
        vector<int> nodes(n);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
        }

        vector<int> leaves;
        findLeafNodes(nodes, 0, n - 1, leaves);

        int minLeaf = *min_element(leaves.begin(), leaves.end());
        int maxLeaf = *max_element(leaves.begin(), leaves.end());
        cout << abs(maxLeaf - minLeaf) << endl;
    }

    return 0;
}
