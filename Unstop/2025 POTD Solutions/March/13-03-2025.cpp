/*
Problem of the Day: Minimum Cost Palindromic Cuts
Problem Description: https://unstop.com/code/practice/541196
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int minPartitionCost(const string &s) {
    int n = s.length();

    vector<int> dp(n, INT_MAX);
    vector<int> asciiCost(n, 0);
  
    for (int i = 0; i < n; ++i) {
        if (isPalindrome(s, 0, i)) {
            dp[i] = 0;
        } else {
            for (int j = 0; j < i; ++j) {
                if (isPalindrome(s, j + 1, i)) {
                    int cost = s[j] + s[i];
                    dp[i] = min(dp[i], dp[j] + cost);
                }
            }
        }
    }

    return dp[n - 1];
}

int main() {
    string S;
    cin >> S;

    int result = minPartitionCost(S);
    cout << result << endl;

    return 0;
}
