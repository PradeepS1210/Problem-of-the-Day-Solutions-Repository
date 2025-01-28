/*
Problem of the Day: Permutations of a String
Problem Description: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
*/

class Solution {
public:
    void backtrack(string &s, int idx, vector<string> &res, unordered_set<string> &uniques) {
        if (idx == s.size()) {
            if (uniques.find(s) == uniques.end()) {
                res.push_back(s);
                uniques.insert(s);
            }
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            swap(s[idx], s[i]);
            backtrack(s, idx + 1, res, uniques);
            swap(s[idx], s[i]);  // backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> res;
        unordered_set<string> uniques;
        backtrack(s, 0, res, uniques);
        return res;
    }
};
