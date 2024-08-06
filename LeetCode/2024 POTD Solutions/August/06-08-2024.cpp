/*
Problem of the Day: 3016. Minimum Number of Pushes to Type Word II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/3016-minimum-number-of-pushes-to-type-word-ii-leetcode-solution-a28f197c25a1
*/

class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> freq;

        for (char ch : word)
        {
            freq[ch]++;
        }

        vector<int> frequencies;
        for (auto &entry : freq)
        {
            frequencies.push_back(entry.second);
        }
        sort(frequencies.begin(), frequencies.end(), greater<int>());

        int totalPushes = 0;
        int keyNumber = 1;
        int pushCount = 1;

        for (int i = 0; i < frequencies.size(); ++i)
        {
            totalPushes += pushCount * frequencies[i];

            if ((i + 1) % 8 == 0)
            {
                pushCount++;
            }
        }

        return totalPushes;
    }
};