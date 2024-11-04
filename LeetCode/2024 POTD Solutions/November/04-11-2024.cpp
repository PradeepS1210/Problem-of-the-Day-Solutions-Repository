/*
Problem of the Day: 3163. String Compression III
Problem Description: https://medium.com/@pradeepsooryavanshee1210/3163-string-compression-iii-leetcode-solution-c493a2b22283
*/

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;
        
        while (i < n) {
            char c = word[i];
            int count = 0;
            
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
            
            comp += to_string(count) + c;
        }
        
        return comp;
    }
};