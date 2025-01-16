/*
Problem of the Day: The Segment Queries
Problem Description: https://unstop.com/code/practice/303835
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> arr(N);
        long long totalSum = 0;

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            totalSum += arr[i];
        }

        while (Q--) {
            char queryType;
            cin >> queryType;

            if (queryType == '!') {
                int L, R, M;
                cin >> L >> R >> M;
                for (int i = L - 1; i < R; ++i) {
                    arr[i] += M;
                    totalSum += M;
                }
            } else if (queryType == '?') {
                cout << totalSum << endl;
            }
        }
    }
    return 0;
}
