/*
Problem of the Day: Count Repetitions
Problem Description: https://unstop.com/code/practice/298455
*/

#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string t, string current) {
    int tIndex = 0, currentIndex = 0;
    while (tIndex < t.size() && currentIndex < current.size()) {
        if (t[tIndex] == current[currentIndex]) {
            tIndex++;
        }
        currentIndex++;
    }
    return tIndex == t.size();
}

int findSmallestDay(string s, string t) {
    string current = s;
    int day = 1;

    while (!isSubsequence(t, current)) {
        current += s;
        day++;
    }

    return day;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << findSmallestDay(s, t) << endl;

    return 0;
}
