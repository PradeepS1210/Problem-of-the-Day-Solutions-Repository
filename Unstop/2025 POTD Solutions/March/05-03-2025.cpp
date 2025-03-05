/*
Problem of the Day: Generate Modified String
Problem Description: https://unstop.com/code/practice/301986
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string convertString(int N, string S) {
    vector<int> primes;

    for (char ch : S) {
        if (isdigit(ch)) {
            int num = ch - '0';
            if (isPrime(num)) {
                primes.push_back(num);
            }
        }
    }

    int uniqueNumber = 0;
    if (!primes.empty()) {
        int sum = accumulate(primes.begin(), primes.end(), 0);
        uniqueNumber = sum / primes.size();
    }

    for (char &ch : S) {
        if (isdigit(ch)) {
            int num = ch - '0';
            int index;
            if (!primes.empty()) {
                index = num % uniqueNumber;
            } else {
                index = num;
            }
            ch = 'a' + index;
        }
    }

    return S;
}

int main() {
    int N;
    string S;

    cin >> N >> S;
  
    cout << convertString(N, S) << endl;

    return 0;
}
