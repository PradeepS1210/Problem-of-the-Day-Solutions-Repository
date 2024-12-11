/*
Problem of the Day: Unique Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/unique-number-unstop-solution-42e01f546c34
*/

#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long findA(long long N) {
    long long A = (N % MOD + MOD) % MOD;
    return A;
}

int main() {
    long long N;
    cin >> N;

    long long A = findA(N);
    cout << A << endl;

    return 0;
}