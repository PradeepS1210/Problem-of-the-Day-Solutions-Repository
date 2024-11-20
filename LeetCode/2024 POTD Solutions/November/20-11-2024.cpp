/*
Problem of the Day: 2516. Take K of Each Character From Left and Right
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2516-take-k-of-each-character-from-left-and-right-leetcode-solution-fb427c727e04
*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> total(3, 0);
        for (char c : s) {
            total[c - 'a']++;
        }

        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }

        int n = s.size();
        vector<int> window(3, 0);
        int maxWindowSize = 0;

        int left = 0;
        for (int right = 0; right < n; ++right) {
            window[s[right] - 'a']++;

            while (window[0] > total[0] - k || 
                   window[1] > total[1] - k || 
                   window[2] > total[2] - k) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindowSize = max(maxWindowSize, right - left + 1);
        }

        return n - maxWindowSize;
    }
};