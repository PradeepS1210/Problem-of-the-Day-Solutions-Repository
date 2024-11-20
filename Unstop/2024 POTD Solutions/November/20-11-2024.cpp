/*
Problem of the Day: Parenthesis
Problem Description: https://medium.com/@pradeepsooryavanshee1210/parenthesis-unstop-solution-1dd910d569d9
*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isMagicalString(const string& s) {
    stack<char> stack;
    unordered_map<char, char> powerPairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty() || stack.top() != powerPairs[c]) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    string s;
    cin >> s;

    if (isMagicalString(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}