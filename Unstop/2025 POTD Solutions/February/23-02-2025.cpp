/*
Problem of the Day: The Quest for the Secure Vault
Problem Description: https://unstop.com/code/practice/519552
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long countValidPINs(int N) {
    long long primeDigitCount = 4;
    long long evenDigitCount = 5;
    long long primePositions = 0;
    long long nonPrimePositions = 0;

    for (int i = 1; i <= N; ++i) {
        if (isPrime(i)) {
            primePositions++;
        } else {
            nonPrimePositions++;
        }
    }

    long long totalPINs = 1;
    for (int i = 0; i < primePositions; ++i) {
        totalPINs = (totalPINs * primeDigitCount) % MOD;
    }
    for (int i = 0; i < nonPrimePositions; ++i) {
        totalPINs = (totalPINs * evenDigitCount) % MOD;
    }

    return totalPINs;
}

int main() {
    int N;
    cin >> N;
    cout << countValidPINs(N) << endl;
    return 0;
}
