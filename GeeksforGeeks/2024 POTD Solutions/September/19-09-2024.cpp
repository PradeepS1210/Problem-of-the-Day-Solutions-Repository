/*
Problem of the Day: Reverse Words
Problem Description: https://medium.com/@pradeepsooryavanshee1210/reverse-words-geeksforgeeks-solution-f325bd45d7a5
*/

class Solution
{
public:
    string reverseWords(string str)
    {
        vector<string> words;
        string word = "";

        for (char c : str)
        {
            if (c == '.')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += c;
            }
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i != words.size() - 1)
            {
                result += ".";
            }
        }

        return result;
    }
};