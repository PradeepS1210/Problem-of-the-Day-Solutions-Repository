/*
Problem of the Day: 884. Uncommon Words from Two Sentences
Problem Description: https://medium.com/@pradeepsooryavanshee1210/884-uncommon-words-from-two-sentences-leetcode-solution-5b516ad15fd0
*/

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> wordCount;

        auto countWords = [&](const string &sentence)
        {
            stringstream ss(sentence);
            string word;
            while (ss >> word)
            {
                wordCount[word]++;
            }
        };

        countWords(s1);
        countWords(s2);

        vector<string> result;
        for (const auto &entry : wordCount)
        {
            if (entry.second == 1)
            {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};