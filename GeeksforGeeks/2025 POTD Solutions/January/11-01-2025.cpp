/*
Asked in Amazon, Microsoft, Housing.com, Adobe
Problem of the Day: Longest substring with distinct characters
Problem Description: https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
*/

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (lastIndex.find(s[end]) != lastIndex.end()) {
                start = max(start, lastIndex[s[end]] + 1);
            }
            lastIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};