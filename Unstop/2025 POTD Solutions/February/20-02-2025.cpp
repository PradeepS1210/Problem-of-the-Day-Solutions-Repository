/*
Problem of the Day: Help Lily
Problem Description: https://unstop.com/code/practice/260571
*/

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 2 << endl;
        return 0;
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<long long> L(N + 1);
    L[0] = 2;
    L[1] = 1;
    for (int i = 2; i <= N; ++i) {
        L[i] = (L[i - 1] + L[i - 2]) % MOD;
    }

    cout << L[N] << endl;
    return 0;
}
