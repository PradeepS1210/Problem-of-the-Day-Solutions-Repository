/*
Problem of the Day: Longest String Chain
Problem Description: https://www.geeksforgeeks.org/problems/longest-string-chain/1
*/

class Solution {
public:
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int maxLength = 1;

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        for (const string &word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);
        }

        return maxLength;
    }
};
