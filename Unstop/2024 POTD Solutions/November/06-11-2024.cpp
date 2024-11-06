/*
Problem of the Day: Maximum Power
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-power-unstop-solution-eb943bc357f8
*/

#include <iostream>
#include <vector>
using namespace std;

int canPartition(vector<int>& arr) {
    int N = arr.size();
    
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }
    
    if (total_sum % 2 != 0) {
        return 0;
    }
    
    int target = total_sum / 2;
    
    vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));
    
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[N][target] ? target : 0;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int result = canPartition(arr);
    cout << result << endl;
    
    return 0;
}