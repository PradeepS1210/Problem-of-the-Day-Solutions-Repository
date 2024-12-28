/*
Problem of the Day: Is Summation
Problem Description: https://unstop.com/code/practice/261198
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string isSubsetSum(int N, int K, vector<int>& arr) {
        vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
        
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[N][K] ? "YES" : "NO";
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    Solution sol;
    cout << sol.isSubsetSum(N, K, arr) << endl;
    return 0;
}
