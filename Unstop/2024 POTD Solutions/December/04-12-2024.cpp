/*
Problem of the Day: Magical Index
Problem Description: https://medium.com/@pradeepsooryavanshee1210/magical-index-unstop-solution-a44cd00c6a10
*/

#include <bits/stdc++.h>
using namespace std;

int findMagicalIndex(vector<int>& arr) {
    int n = arr.size();

    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int leftSum = 0;

    for (int i = 0; i < n; ++i) {
        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            return i + 1;
        }

        leftSum += arr[i];
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findMagicalIndex(arr);

    cout << result << endl;

    return 0;
}