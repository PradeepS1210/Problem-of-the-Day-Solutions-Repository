/*
Problem of the Day: Perfect Binary Tree
Problem Description: https://unstop.com/code/practice/277797
*/

#include <bits/stdc++.h>
using namespace std;

long long minIncrement(int N, vector<int>& weights) {
    int totalNodes = (1 << (N + 1)) - 1;
    vector<long long> W(totalNodes + 1, 0);
    for (int i = 2; i <= totalNodes; ++i) {
        W[i] = weights[i - 2];
    }

    vector<long long> maxPathSum(totalNodes + 1, 0);
    long long totalIncrements = 0;

    for (int node = totalNodes; node > 0; --node) {
        if (2 * node > totalNodes) {
            maxPathSum[node] = 0;
        } else {
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            long long leftPath = W[leftChild] + maxPathSum[leftChild];
            long long rightPath = W[rightChild] + maxPathSum[rightChild];

            totalIncrements += abs(leftPath - rightPath);
            maxPathSum[node] = max(leftPath, rightPath);
        }
    }

    return totalIncrements;
}

int main() {
    int N;
    cin >> N;
    int edgeCount = (1 << (N + 1)) - 2;
    vector<int> weights(edgeCount);
    for (int i = 0; i < edgeCount; ++i) {
        cin >> weights[i];
    }
    cout << minIncrement(N, weights) << endl;
    return 0;
}
