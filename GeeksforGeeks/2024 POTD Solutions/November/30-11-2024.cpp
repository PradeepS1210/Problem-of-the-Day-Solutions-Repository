/*
Asked in Flipkart, Directi, Adobe, Google, Nagarro, Media.net
Problem of the Day: Anagram
Problem Description: https://medium.com/@pradeepsooryavanshee1210/anagram-geeksforgeeks-solution-69e8f0fcdc99
*/

class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        unordered_map<char, int> freqMap;

        for (char c : s1) {
            freqMap[c]++;
        }

        for (char c : s2) {
            freqMap[c]--;
            if (freqMap[c] < 0) {
                return false;
            }
        }

        for (auto& pair : freqMap) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};