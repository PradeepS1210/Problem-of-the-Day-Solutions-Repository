/*
Problem of the Day: Null GL Pair
Problem Description: https://unstop.com/code/practice/293340
*/

#include <bits/stdc++.h>
using namespace std;

int countPairs(int n, vector<int>& num) {
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        mp[num[i]]++;
    }

    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2; 
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    cout << countPairs(n, num) << endl;

    return 0;
}
