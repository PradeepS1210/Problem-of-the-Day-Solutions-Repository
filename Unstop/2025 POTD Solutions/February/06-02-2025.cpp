/*
Problem of the Day: Automated testing
Problem Description: https://unstop.com/code/practice/307002
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    
    unordered_set<int> visited;
    visited.insert(X);
    
    for (char move : S) {
        if (move == 'L') {
            X--;
        } else if (move == 'R') {
            X++;
        }
        visited.insert(X);
    }
    
    cout << visited.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
