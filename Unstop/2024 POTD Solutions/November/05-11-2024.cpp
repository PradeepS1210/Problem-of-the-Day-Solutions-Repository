/*
Problem of the Day: Different Problem
Problem Description: https://medium.com/@pradeepsooryavanshee1210/different-problem-unstop-solution-06a5575482a1
*/

#include <bits/stdc++.h>
using namespace std;

int calculateDifference(int num) {
    string numStr = to_string(abs(num));
    vector<char> sortedDigits(numStr.begin(), numStr.end());
    
    sort(sortedDigits.begin(), sortedDigits.end());
    string minStr(sortedDigits.begin(), sortedDigits.end());
    int minValue = stoi(minStr);

    reverse(sortedDigits.begin(), sortedDigits.end());
    string maxStr(sortedDigits.begin(), sortedDigits.end());
    int maxValue = stoi(maxStr);

    if (num < 0) {
        minValue = -stoi(maxStr);
        maxValue = -stoi(minStr);
    }

    return abs(maxValue - minValue);
}

int main() {
    int T;
    cin >> T;
    vector<int> results;
    
    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        results.push_back(calculateDifference(num));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}