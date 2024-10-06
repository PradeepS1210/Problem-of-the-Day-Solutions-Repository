/*
Problem of the Day: 1813. Sentence Similarity III
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1813-sentence-similarity-iii-leetcode-solution-395d2da02336
*/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }

        int i = 0, j = 0;
        while (i < words2.size() && words1[i] == words2[i]) {
            i++;
        }

        while (j < words2.size() - i && words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }

        return i + j == words2.size();
    }

private:
    vector<string> split(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};