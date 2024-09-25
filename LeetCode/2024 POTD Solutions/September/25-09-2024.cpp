/*
Problem of the Day: 2416. Sum of Prefix Scores of Strings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2416-sum-of-prefix-scores-of-strings-leetcode-solution-d2f1a222c191
*/

class Solution
{
public:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        int count = 0;
    };

    TrieNode *root;

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }

    int getPrefixScore(const string &word)
    {
        TrieNode *node = root;
        int score = 0;
        for (char c : word)
        {
            node = node->children[c];
            score += node->count;
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string> &words)
    {
        root = new TrieNode();
        vector<int> result;

        for (const string &word : words)
        {
            insert(word);
        }

        for (const string &word : words)
        {
            result.push_back(getPrefixScore(word));
        }

        return result;
    }
};