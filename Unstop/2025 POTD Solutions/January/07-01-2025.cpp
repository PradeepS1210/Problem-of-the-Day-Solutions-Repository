/*
Problem of the Day: Peculiar number
Problem Description: https://unstop.com/code/practice/292350
*/

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

bool canPartition(vector<int>& arr, int K, int mid) {
    int count = 1, sum = 0;
    for (int num : arr) {
        if (sum + num > mid) {
            count++;
            sum = num;
            if (count > K) return false;
        } else {
            sum += num;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        arr[i] = abs(arr[i] - i);
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPartition(arr, K, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result < 100) {
        cout << fibonacci(result) << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
