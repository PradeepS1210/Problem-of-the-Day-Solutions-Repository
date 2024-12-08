/*
Problem of the Day: Decode the message
Problem Description: https://medium.com/@pradeepsooryavanshee1210/decode-the-message-unstop-solution-20b128c870f2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string S) {
        string result = "";
        int n = S.length();
        
        for (int i = 0; i < n; ++i) {
            if (i + 2 < n && S[i + 2] == '#') {
                int num = stoi(S.substr(i, 2));
                result += char('a' + num - 1);
                i += 2;
            } else {
                int num = S[i] - '0';
                result += char('a' + num - 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string S;
    cin >> S;
    cout << sol.decodeMessage(S) << endl;
    return 0;
}