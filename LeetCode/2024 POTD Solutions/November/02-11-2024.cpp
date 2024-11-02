/*
Problem of the Day: 2490. Circular Sentence
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2490-circular-sentence-leetcode-solution-14af2b2ec4ec
*/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].back() != words[(i + 1) % n].front()) {
                return false;
            }
        }
        
        return true;
    }
};