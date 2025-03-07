/*
Problem of the Day: Two’s Modulo
Problem Description: https://unstop.com/code/practice/302481
*/

#include <bits/stdc++.h>
using namespace std;

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

bool isPowerOfTwo(long long n) {
    return (n && !(n & (n - 1)));
}

int main() {
    long long N;
    cin >> N;

    long long mod = 10007;

    long long inverse = modInverse(N, mod);

    if (isPowerOfTwo(inverse)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
