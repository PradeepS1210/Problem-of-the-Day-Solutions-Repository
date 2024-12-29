/*
Problem of the Day: The Hint
Problem Description: https://unstop.com/code/practice/260638
*/

#include <iostream>
#include <string>
using namespace std;

int findLongestSubstring(const string& passcode) {
    int maxLength = 0;
    int currentLength = 1;

    for (size_t i = 1; i < passcode.length(); ++i) {
        if (passcode[i] == passcode[i - 1]) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    
    maxLength = max(maxLength, currentLength);

    return maxLength;
}

int main() {
    string passcode;
    cin >> passcode;

    cout << findLongestSubstring(passcode) << endl;
    return 0;
}
