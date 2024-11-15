/*
Problem of the Day: ENCODER GIRL
Problem Description: https://medium.com/@pradeepsooryavanshee1210/encoder-girl-unstop-solution-9d49c57e228f
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    
    char removeChar;
    cin >> removeChar;
    
    vector<int> lengths;
    
    for (const auto& word : words) {
        string modifiedWord;
        
        for (char ch : word) {
            if (ch != removeChar) {
                modifiedWord += ch;
            }
        }
        
        lengths.push_back(modifiedWord.length());
    }
    
    sort(lengths.begin(), lengths.end());
    
    for (int length : lengths) {
        cout << length << " ";
    }
    
    return 0;
}