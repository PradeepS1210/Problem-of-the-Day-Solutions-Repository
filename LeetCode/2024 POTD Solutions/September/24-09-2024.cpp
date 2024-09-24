/*
Problem of the Day: 3043. Find the Length of the Longest Common Prefix
Problem Description: https://medium.com/@pradeepsooryavanshee1210/3043-find-the-length-of-the-longest-common-prefix-leetcode-solution-8539e8e37425
*/

class Solution
{
public:
    struct TrieNode
    {
        TrieNode *children[10] = {nullptr};
    };

    void insert(TrieNode *root, const string &num)
    {
        TrieNode *node = root;
        for (char c : num)
        {
            int idx = c - '0';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int searchPrefix(TrieNode *root, const string &num)
    {
        TrieNode *node = root;
        int prefixLength = 0;
        for (char c : num)
        {
            int idx = c - '0';
            if (node->children[idx])
            {
                node = node->children[idx];
                prefixLength++;
            }
            else
            {
                break;
            }
        }
        return prefixLength;
    }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        TrieNode *root = new TrieNode();
        int maxLength = 0;

        for (int num : arr1)
        {
            insert(root, to_string(num));
        }

        for (int num : arr2)
        {
            maxLength = max(maxLength, searchPrefix(root, to_string(num)));
        }

        return maxLength;
    }
};