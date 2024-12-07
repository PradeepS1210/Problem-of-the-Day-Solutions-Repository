/*
Problem of the Day: Special Sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/special-sum-unstop-solution-202319a7ecb4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<int> uniqueElements(nums.begin(), nums.end());
    long long specialSum = 0;

    for (int x : uniqueElements) {
        specialSum += pow(2, x);
    }

    cout << specialSum << endl;
    return 0;
}