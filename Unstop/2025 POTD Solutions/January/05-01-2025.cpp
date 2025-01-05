/*
Asked in Tech Mahindra, Accolite, TCS
Problem of the Day: Counting Words
Problem Description: https://unstop.com/code/practice/250897
*/

#include <bits/stdc++.h>
using namespace std;

int longest(string str) {
    replace(str.begin(), str.end(), '.', ',');
    stringstream ss(str);
    string sent;
    int maxLen = 0;

    while (getline(ss, sent, ',')) {
        stringstream ws(sent);
        string w;
        int len = 0;

        while (ws >> w) {
            len++;
        }

        maxLen = max(maxLen, len);
    }

    return maxLen;
}

int main() {
    string str;
    getline(cin, str);
    cout << longest(str) << endl;
    return 0;
}
