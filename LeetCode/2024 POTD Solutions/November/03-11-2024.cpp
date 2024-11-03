/*
Problem of the Day: 796. Rotate String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/796-rotate-string-leetcode-solution-77c3fc562bd1
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        string doubled = s + s;
        
        return doubled.find(goal) != string::npos;
    }
};