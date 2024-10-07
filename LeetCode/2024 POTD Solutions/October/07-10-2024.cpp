/*
Problem of the Day: 2696. Minimum String Length After Removing Substrings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2696-minimum-string-length-after-removing-substrings-leetcode-solution-a5f49d0b7720
*/

class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && ((stk.top() == 'A' && c == 'B') || (stk.top() == 'C' && c == 'D'))) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};