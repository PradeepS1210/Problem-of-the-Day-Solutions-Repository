/*
Problem of the Day: 214. Shortest Palindrome
Problem Description: https://medium.com/@pradeepsooryavanshee1210/214-shortest-palindrome-leetcode-solution-97e3e520e52b
*/

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        string temp = s + "#" + rev_s;
        int n = temp.size();

        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++)
        {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j])
            {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j])
            {
                j++;
            }
            lps[i] = j;
        }

        int palindrome_len = lps.back();

        string result = rev_s.substr(0, rev_s.size() - palindrome_len) + s;

        return result;
    }
};