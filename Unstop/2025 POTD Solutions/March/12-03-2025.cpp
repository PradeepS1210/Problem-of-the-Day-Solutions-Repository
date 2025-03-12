/*
Problem of the Day: Min-Max Window Difference
Problem Description: https://unstop.com/code/practice/540227
*/

#include <bits/stdc++.h>
using namespace std;

int findMinMaxDifference(vector<int>& arr, int k) {
    deque<int> maxDeque, minDeque;
    int n = arr.size(), minDifference = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!maxDeque.empty() && maxDeque.front() == i - k) maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() == i - k) minDeque.pop_front();

        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[i])
            maxDeque.pop_back();
        maxDeque.push_back(i);

        while (!minDeque.empty() && arr[minDeque.back()] >= arr[i])
            minDeque.pop_back();
        minDeque.push_back(i);

        if (i >= k - 1) {
            int maxVal = arr[maxDeque.front()];
            int minVal = arr[minDeque.front()];
            minDifference = min(minDifference, maxVal - minVal);
        }
    }
    return minDifference;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    cout << findMinMaxDifference(arr, k) << endl;

    return 0;
}
