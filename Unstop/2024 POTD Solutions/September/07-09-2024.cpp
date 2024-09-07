/*
Asked in Karat, Indeed, Facebook, Amazon, American express, bloomberg, Xome
Problem of the Day: Find possible words
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-possible-words-unstop-solution-c21e24dc1880
*/

#include <bits/stdc++.h>
using namespace std;

bool canFormWord(string word, unordered_map<char, int> charCount)
{
    for (char ch : word)
    {
        if (charCount[ch] > 0)
        {
            charCount[ch]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> W(n);

    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    string C;
    cin >> C;

    unordered_map<char, int> charCount;
    for (char ch : C)
    {
        charCount[ch]++;
    }

    int totalLength = 0;

    for (const string &word : W)
    {
        if (canFormWord(word, charCount))
        {
            totalLength += word.length();
        }
    }

    cout << totalLength << endl;

    return 0;
}