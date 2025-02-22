/*
Problem of the Day: Longest valid Parentheses
Problem Description: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
*/

class Solution {
public:
    int maxLength(string& s) {
        stack<int> stack;
        stack.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    max_len = max(max_len, i - stack.top());
                }
            }
        }
        return max_len;
    }
};
