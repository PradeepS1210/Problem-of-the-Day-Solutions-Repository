/*
Problem of the Day: Reverse Vowels Code
Problem Description: https://unstop.com/code/practice/303801
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countReversedVowel(string s) {
        string vowels = "aeiou";
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (vowels.find(s[left]) == string::npos) {
                left++;
            } else if (vowels.find(s[right]) == string::npos) {
                right--;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        string target = "code";
        int count = 0;
        for (size_t i = 0; i <= s.size() - target.size(); i++) {
            if (s.substr(i, target.size()) == target) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.countReversedVowel(s) << endl;
    return 0;
}
