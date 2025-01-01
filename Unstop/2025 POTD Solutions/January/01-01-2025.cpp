/*
Problem of the Day: Pairing Lucky Stones in the Village Festival
Problem Description: https://unstop.com/code/practice/501184
*/

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& stones, int N, int M) {
    int P = stones.size();
    unordered_set<int> seen;
    int pairCount = 0;

    for (int i = 0; i < P; ++i) {
        for (int j = i + 1; j < P; ++j) {
            if ((stones[i] % N == 0 || stones[i] % M == 0) &&
                (stones[j] % N == 0 || stones[j] % M == 0)) {
                pairCount++;
            }
        }
    }

    return pairCount;
}

int main() {
    int P, N, M;
    cin >> P >> N >> M;

    vector<int> stones(P);
    for (int i = 0; i < P; ++i) {
        cin >> stones[i];
    }

    int result = countPairs(stones, N, M);
    cout << result << endl;

    return 0;
}
