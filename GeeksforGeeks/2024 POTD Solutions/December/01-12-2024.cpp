/*
Problem of the Day: Non Repeating Character
Problem Description: https://medium.com/@pradeepsooryavanshee1210/non-repeating-character-geeksforgeeks-solution-75c42a1cd084
*/

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }

        return '$';
    }
};