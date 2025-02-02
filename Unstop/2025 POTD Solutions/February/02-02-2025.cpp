/*
Problem of the Day: Odd Frequency
Problem Description: https://unstop.com/code/practice/295750
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    unordered_map<char, int> freq;
    
    for (char ch : str) {
        freq[ch]++;
    }
    
    int oddCount = 0;
    
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            oddCount++;
        }
    }
    
    if (oddCount >= 3) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
