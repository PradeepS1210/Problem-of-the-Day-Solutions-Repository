/*
Problem of the Day: 1371. Find the Longest Substring Containing Vowels in Even Counts
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1371-find-the-longest-substring-containing-vowels-in-even-counts-leetcode-solution-cd3fad16b76a
*/

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<int, int> mask_map;
        mask_map[0] = -1;

        int mask = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'a')
                mask ^= (1 << 0);
            else if (s[i] == 'e')
                mask ^= (1 << 1);
            else if (s[i] == 'i')
                mask ^= (1 << 2);
            else if (s[i] == 'o')
                mask ^= (1 << 3);
            else if (s[i] == 'u')
                mask ^= (1 << 4);

            if (mask_map.find(mask) != mask_map.end())
            {
                max_len = max(max_len, i - mask_map[mask]);
            }
            else
            {
                mask_map[mask] = i;
            }
        }

        return max_len;
    }
};