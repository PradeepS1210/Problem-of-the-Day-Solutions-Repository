/*
Problem of the Day: Sort By Frequency
Problem Description: https://unstop.com/code/practice/261825
*/

#include <bits/stdc++.h>
using namespace std;

string sortByFrequency(string S) {
    unordered_map<char, int> freqMap;
    unordered_map<char, int> firstIndex;

    for (int i = 0; i < S.length(); i++) {
        freqMap[S[i]]++;
        if (firstIndex.find(S[i]) == firstIndex.end()) {
            firstIndex[S[i]] = i;
        }
    }

    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

    sort(freqVec.begin(), freqVec.end(), [&](pair<char, int>& a, pair<char, int>& b) {
        if (a.second == b.second) {
            return firstIndex[a.first] < firstIndex[b.first];
        }
        return a.second > b.second;
    });

    string result = "";
    for (auto& entry : freqVec) {
        result += string(entry.second, entry.first);
    }
    
    return result;
}

int main() {
    string S;
    cin >> S;
    cout << sortByFrequency(S) << endl;
    return 0;
}
