/*
Problem of the Day: Minimum Largest Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-largest-number-unstop-solution-19ef426caf88
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int smallest = arr[0];
    int second_smallest = arr[1];

    int largest_number = second_smallest * 10 + smallest;

    cout << largest_number << endl;

    return 0;
}