/*
Problem of the Day: 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1455-check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence-leetcode-solution-0baad4745880
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        string currentWord = "";
        
        for (char ch : sentence) {
            if (ch == ' ') {
                if (currentWord.find(searchWord) == 0) {
                    return index;
                }
                index++;
                currentWord = "";
            } else {
                currentWord += ch;
            }
        }
        
        if (currentWord.find(searchWord) == 0) {
            return index;
        }
        
        return -1;
    }
};