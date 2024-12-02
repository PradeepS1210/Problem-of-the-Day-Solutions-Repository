/*
Problem of the Day: Min Chars to Add for Palindrome
Problem Description: https://medium.com/@pradeepsooryavanshee1210/min-chars-to-add-for-palindrome-geeksforgeeks-solution-85422b111f19
*/

class Solution {
  public:
    int minChar(string& s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string combined = s + '#' + rev_s;
        
        int n = combined.size();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        return s.size() - lps[n - 1];
    }
};