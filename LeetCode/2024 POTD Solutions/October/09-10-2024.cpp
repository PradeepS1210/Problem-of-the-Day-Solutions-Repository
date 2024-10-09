/*
Problem of the Day: 921. Minimum Add to Make Parentheses Valid
Problem Description: https://medium.com/@pradeepsooryavanshee1210/921-minimum-add-to-make-parentheses-valid-leetcode-solution-2bd83d76d180
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int closeCount = 0;
        
        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--;
                } else {
                    closeCount++;
                }
            }
        }
        
        return openCount + closeCount;
    }
};