/*
Problem of the Day: Prime Coins
Problem Description: https://unstop.com/code/practice/293472
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

vector<long long> factorialMod(int n) {
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return fact;
}

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime = sieve(n);
    int primeCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (isPrime[i]) primeCount++;
    }

    vector<long long> fact = factorialMod(n);

    int nonPrimeCount = n - primeCount;

    long long result = (fact[primeCount] * fact[nonPrimeCount]) % MOD;

    cout << result << endl;

    return 0;
}
