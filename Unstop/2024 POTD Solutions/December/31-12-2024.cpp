/*
Problem of the Day: Octal Pattern Count
Problem Description: https://unstop.com/code/practice/293607
*/

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int countValidStrings(int N) {
    if (N == 0) return 1;

    vector<vector<int>> transitions = {
        {1, 4},
        {0, 2},
        {1, 3},
        {2, 4},
        {0, 3}
    };

    vector<long long> dp(5, 1), temp(5);

    for (int len = 2; len <= N; ++len) {
        fill(temp.begin(), temp.end(), 0);
        for (int vowel = 0; vowel < 5; ++vowel) {
            for (int next : transitions[vowel]) {
                temp[next] = (temp[next] + dp[vowel]) % MOD;
            }
        }
        dp = temp;
    }

    long long total = 0;
    for (int count : dp) {
        total = (total + count) % MOD;
    }

    return total;
}

string decimalToOctal(int num) {
    if (num == 0) return "0";
    string octal = "";
    while (num > 0) {
        octal = to_string(num % 8) + octal;
        num /= 8;
    }
    return octal;
}

int main() {
    int N;
    cin >> N;

    int validStrings = countValidStrings(N);
    string octalResult = decimalToOctal(validStrings);

    cout << octalResult << endl;

    return 0;
}
