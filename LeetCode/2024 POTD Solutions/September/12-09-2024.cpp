/*
Problem of the Day: 1684. Count the Number of Consistent Strings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1684-count-the-number-of-consistent-strings-leetcode-solution-120f07101fe1
*/

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        vector<bool> isAllowed(26, false);

        for (char c : allowed)
        {
            isAllowed[c - 'a'] = true;
        }

        int consistentCount = 0;

        for (string word : words)
        {
            bool isConsistent = true;
            for (char c : word)
            {
                if (!isAllowed[c - 'a'])
                {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent)
            {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};