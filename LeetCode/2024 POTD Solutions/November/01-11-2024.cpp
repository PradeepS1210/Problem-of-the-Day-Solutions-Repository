/*
Problem of the Day: 1957. Delete Characters to Make Fancy String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1957-delete-characters-to-make-fancy-string-leetcode-solution-11fdaf231104
*/

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        
        for (int i = 0; i < s.size(); ++i) {
            if (result.size() >= 2 && result[result.size() - 1] == s[i] && result[result.size() - 2] == s[i]) {
                continue;
            }
            result += s[i];
        }
        
        return result;
    }
};