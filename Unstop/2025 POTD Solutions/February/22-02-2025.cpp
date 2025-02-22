/*
Problem of the Day: Power and Score of Array Elements
Problem Description: https://unstop.com/code/practice/515948
*/

#include <bits/stdc++.h>
using namespace std;

int calculateScore(const vector<int>& arr, int n) {
    vector<int> before(n, INT_MAX);
    vector<int> after(n, INT_MAX);
    set<int> left, right;
  
    for (int i = 0; i < n; ++i) {
        if (left.size() >= 2) {
            auto it = left.begin();
            ++it;
            before[i] = *it;
        }
        left.insert(arr[i]);
    }
  
    for (int i = n - 1; i >= 0; --i) {
        if (right.size() >= 2) {
            auto it = right.begin();
            ++it;
            after[i] = *it;
        }
        right.insert(arr[i]);
    }
  
    int score = 0;
    for (int i = 0; i < n; ++i) {
        score += max(arr[i] - before[i], arr[i] - after[i]);
    }

    return score;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int score = calculateScore(arr, n);
    cout << score << endl;

    return 0;
}
