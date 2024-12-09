/*
Problem of the Day: Special Message
Problem Description: https://medium.com/@pradeepsooryavanshee1210/special-message-unstop-solution-7aa6e51c17b0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceAcronyms(string S, int N, unordered_map<string, string> &keyValuePairs) {
        string result = "";
        string temp = "";
        bool isAcronym = false;

        for (char c : S) {
            if (c == '(') {
                if (!temp.empty()) {
                    result += temp;
                    temp.clear();
                }
                isAcronym = true;
            } else if (c == ')') {
                if (isAcronym) {
                    result += (keyValuePairs.count(temp) ? keyValuePairs[temp] : "?");
                    temp.clear();
                    isAcronym = false;
                }
            } else {
                if (isAcronym) {
                    temp += c;
                } else {
                    result += c;
                }
            }
        }

        if (!temp.empty()) {
            result += temp;
        }

        return result;
    }
};

int main() {
    string S;
    getline(cin, S);

    int N;
    cin >> N;
    unordered_map<string, string> keyValuePairs;

    cin.ignore();
    for (int i = 0; i < N; i++) {
        string key, value;
        cin >> key;
        cin.ignore();
        getline(cin, value);
        keyValuePairs[key] = value;
    }

    Solution sol;
    string output = sol.replaceAcronyms(S, N, keyValuePairs);
    cout << output << endl;

    return 0;
}