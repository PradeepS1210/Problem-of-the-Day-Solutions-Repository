/*
Problem of the Day: Minimum repeat to make substring
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-repeat-to-make-substring-geeksforgeeks-solution-e6293cebb0ca
*/

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string repeated = s1;
        int count = 1;

        while (repeated.length() < s2.length()) {
            repeated += s1;
            count++;
        }

        if (repeated.find(s2) != string::npos) {
            return count;
        }

        repeated += s1;
        count++;

        if (repeated.find(s2) != string::npos) {
            return count;
        }

        return -1;
    }
};