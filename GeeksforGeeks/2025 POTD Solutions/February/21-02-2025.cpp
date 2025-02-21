/*
Problem of the Day: Parenthesis Checker
Problem Description: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/

class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
