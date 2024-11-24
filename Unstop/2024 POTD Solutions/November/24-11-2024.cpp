/*
Problem of the Day: Small Big Pattern
Problem Description: https://medium.com/@pradeepsooryavanshee1210/small-big-pattern-unstop-solution-905c0411565d
*/

#include <bits/stdc++.h>
using namespace std;

int longestZigZag(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return n;

    int up = 1, down = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1;
        }
    }

    return max(up, down);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << longestZigZag(arr) << endl;
    return 0;
}