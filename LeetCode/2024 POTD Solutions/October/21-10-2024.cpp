/*
Problem of the Day: 1593. Split a String Into the Max Number of Unique Substrings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1593-split-a-string-into-the-max-number-of-unique-substrings-leetcode-solution-4bb7c6997e4b
*/

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        return backtrack(s, 0, used);
    }
    
    int backtrack(const string& s, int start, unordered_set<string>& used) {
        if (start == s.length()) {
            return 0;
        }
        
        int maxSplit = 0;
        
        string current = "";
        for (int i = start; i < s.length(); ++i) {
            current += s[i];
            if (used.find(current) == used.end()) {
                used.insert(current);
                maxSplit = max(maxSplit, 1 + backtrack(s, i + 1, used));
                used.erase(current);
            }
        }
        
        return maxSplit;
    }
};
