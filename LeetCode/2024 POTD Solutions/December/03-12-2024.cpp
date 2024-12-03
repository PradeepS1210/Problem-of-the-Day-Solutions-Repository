/*
Problem of the Day: 2109. Adding Spaces to a String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2109-adding-spaces-to-a-string-leetcode-solution-2cad05d68e32
*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size();
        int m = spaces.size();
        int spaceIndex = 0;
        int i = 0;

        while (i < n) {
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                result += ' ';
                spaceIndex++;
            }
            result += s[i];
            i++;
        }

        return result;
    }
};