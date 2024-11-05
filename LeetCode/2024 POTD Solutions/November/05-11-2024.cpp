/*
Problem of the Day: 2914. Minimum Number of Changes to Make Binary String Beautiful
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2914-minimum-number-of-changes-to-make-binary-string-beautiful-leetcode-solution-611e396c7853
*/

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int changes = 0;

        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};