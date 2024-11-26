/*
Problem of the Day: Substrate of maximum and minimum value
Problem Description: https://medium.com/@pradeepsooryavanshee1210/substrate-of-maximum-and-minimum-value-unstop-solution-4765c1c1a025
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int mean = (minValue + maxValue) / 2;

    cout << mean << endl;

    return 0;
}