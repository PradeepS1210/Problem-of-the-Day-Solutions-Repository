/*
Problem of the Day: Galaxy Treasure Hunt: Finding the Elusive Substring
Problem Description: https://unstop.com/code/practice/499137
*/

#include <bits/stdc++.h>
using namespace std;

int minLengthSubstring(const string &S, const string &T) {
    unordered_map<char, int> targetFreq;
    for (char c : T) {
        targetFreq[c]++;
    }

    unordered_map<char, int> windowFreq;
    int left = 0, right = 0;
    int formed = 0, required = targetFreq.size();
    int minLength = INT_MAX, start = 0;

    while (right < S.length()) {
        char c = S[right];
        windowFreq[c]++;
        if (targetFreq.find(c) != targetFreq.end() && windowFreq[c] == targetFreq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = S[left];
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }
            windowFreq[c]--;
            if (targetFreq.find(c) != targetFreq.end() && windowFreq[c] < targetFreq[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main() {
    string S, T;
    cin >> S;
    cin >> T;

    int result = minLengthSubstring(S, T);

    cout << result << endl;

    return 0;
}
