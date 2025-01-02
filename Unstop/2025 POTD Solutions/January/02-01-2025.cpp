/*
Problem of the Day: Arjun's Fibonacci Treasure Hunt
Problem Description: https://unstop.com/code/practice/495580
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> extractNums(const string &s) {
    vector<int> nums;
    string temp = "";
    for (char ch : s) {
        if (isdigit(ch)) {
            temp += ch;
        } else if (!temp.empty()) {
            nums.push_back(stoi(temp));
            temp = "";
        }
    }
    if (!temp.empty()) {
        nums.push_back(stoi(temp));
    }
    return nums;
}

set<int> genFib(int maxVal) {
    set<int> fib;
    int a = 0, b = 1;
    fib.insert(a);
    fib.insert(b);
    while (b <= maxVal) {
        int next = a + b;
        if (next > maxVal) break;
        fib.insert(next);
        a = b;
        b = next;
    }
    return fib;
}

vector<int> genFirstKFib(int k) {
    vector<int> fib;
    int a = 0, b = 1;
    if (k > 0) fib.push_back(a);
    if (k > 1) fib.push_back(b);
    for (int i = 2; i < k; ++i) {
        int next = a + b;
        fib.push_back(next);
        a = b;
        b = next;
    }
    return fib;
}

int main() {
    string s;
    cin >> s;

    vector<int> nums = extractNums(s);

    int maxVal = *max_element(nums.begin(), nums.end());

    set<int> fibSet = genFib(maxVal);

    vector<int> fibNums;
    for (int num : nums) {
        if (fibSet.find(num) != fibSet.end()) {
            fibNums.push_back(num);
        }
    }

    if (fibNums.empty()) {
        cout << 0 << endl;
    } else {
        cout << fibNums.size() << endl;

        for (int num : fibNums) {
            cout << num << " ";
        }
        cout << endl;

        vector<int> firstKFib = genFirstKFib(fibNums.size());
        for (int num : firstKFib) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
