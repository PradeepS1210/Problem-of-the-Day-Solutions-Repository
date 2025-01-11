/*
Problem of the Day: Pirate-Proof Gold Words: Aftab's Dilemma
Problem Description: https://unstop.com/code/practice/451375
*/

#include <bits/stdc++.h>
using namespace std;

int countDistinctMessages(const string &msg) {
    unordered_set<string> distinctMsgs;
    int n = msg.size();

    for (int i = 0; i < n - 1; ++i) {
        string newMsg = msg.substr(0, i) + msg.substr(i + 2);
        distinctMsgs.insert(newMsg);
    }

    return distinctMsgs.size();
}

int main() {
    string msg;
    cin >> msg;
    
    int result = countDistinctMessages(msg);
    cout << result << endl;

    return 0;
}
