/*
Problem of the Day: 567. Permutation in String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/567-permutation-in-string-leetcode-solution-e824f0d58a0a
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if (n > m) return false;
        
        vector<int> s1_count(26, 0), s2_count(26, 0);
        
        for (int i = 0; i < n; i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        if (s1_count == s2_count) return true;
        
        for (int i = n; i < m; i++) {
            s2_count[s2[i] - 'a']++;
            s2_count[s2[i - n] - 'a']--;
            
            if (s1_count == s2_count) return true;
        }
        
        return false;
    }
};