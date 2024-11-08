/*
Problem of the Day: Maximum Length Subsequence
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-length-subsequence-unstop-solution-dac23ee9825c
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve(const string& str) {
    int ans = 0;
    unordered_map<char, int> mp;
    
    for (char i : str) {
        mp[i] = max(1, mp[i]);
        
        char first = i - 2;
        char second = i + 2;
        
        mp[i] = max({1, mp[i], mp[first] + 1, mp[second] + 1});
        
        ans = max(ans, mp[i]);
    }
    
    return ans;
}

int main() {
    string s;
    cin >> s;
    
    if (isPrime(solve(s))) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}