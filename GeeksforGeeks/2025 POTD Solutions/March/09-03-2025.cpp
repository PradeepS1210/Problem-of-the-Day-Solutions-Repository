/*
Problem of the Day: Palindrome SubStrings
Problem Description: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1
*/

class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        auto countPalindromes = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) {
                    count++;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            countPalindromes(i, i);
            countPalindromes(i, i + 1);
        }

        return count;
    }
};
