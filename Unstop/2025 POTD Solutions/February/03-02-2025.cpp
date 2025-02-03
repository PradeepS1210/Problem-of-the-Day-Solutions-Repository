/*
Problem of the Day: Pole Arrangement
Problem Description: https://unstop.com/code/practice/295752
*/

#include <bits/stdc++.h>
using namespace std;

void changeLongest(vector<int>& arr, int x) {
    int maxx = *max_element(arr.begin(), arr.end());
    for (int& height : arr) {
        if (height == maxx) {
            height = max(0, height - x);
        }
    }
}

bool poleArrangement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> pre_min(n);
    pre_min[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        pre_min[i] = min(pre_min[i - 1], arr[i]);
    }

    stack<int> st;

    for (int j = n - 1; j >= 0; --j) {
        if (arr[j] > pre_min[j]) {
            while (!st.empty() && st.top() <= pre_min[j]) {
                st.pop();
            }
            if (!st.empty() && st.top() < arr[j]) {
                return true;
            }
            st.push(arr[j]);
        }
    }

    return false;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    changeLongest(arr, x);
    cout << poleArrangement(arr) << endl;
    
    return 0;
}
