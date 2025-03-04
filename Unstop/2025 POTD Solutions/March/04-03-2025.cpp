/*
Problem of the Day: Balanced Partition Problem
Problem Description: https://unstop.com/code/practice/536886
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    if (N == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> prefix(N);
    prefix[0] = arr[0];
    for (int i = 1; i < N; ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    int total_sum = prefix[N - 1];
    
    int best_diff = INT_MAX;
    bool valid_found = false;
    
    for (int i = 0; i < N - 1; ++i) {
        if (arr[i] - arr[0] > K) {
            break;
        }
        
        if (arr[N - 1] - arr[i + 1] <= K) {
            int left_sum = prefix[i];
            int right_sum = total_sum - left_sum;
            int diff = abs(left_sum - right_sum);
            best_diff = min(best_diff, diff);
            valid_found = true;
        }
    }
    
    cout << (valid_found ? best_diff : -1) << endl;
    
    return 0;
}
