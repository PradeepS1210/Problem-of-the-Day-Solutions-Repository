/*
Problem of the Day: Max sum after partitioning
Problem Description: https://medium.com/@pradeepsooryavanshee1210/max-sum-after-partitioning-unstop-solution-38656171b32c
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int countPrimes(int M) {
    if (M < 2) return 0;
    
    vector<bool> isPrime(M + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= M; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= M; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    int primeCount = 0;
    for (int i = 2; i <= M; ++i) {
        if (isPrime[i]) primeCount++;
    }
    
    return primeCount;
}

int maxSumAfterPartitioning(vector<int>& arr, int N, int K) {
    vector<int> dp(N + 1, 0);
    
    for (int i = 1; i <= N; ++i) {
        int maxVal = arr[i - 1];
        for (int k = 1; k <= K && i - k >= 0; ++k) {
            maxVal = max(maxVal, arr[i - k]);
            dp[i] = max(dp[i], dp[i - k] + maxVal * k);
        }
    }
    
    return dp[N];
}

int main() {
    int N, K;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    cin >> K;
    
    int maxSum = maxSumAfterPartitioning(arr, N, K);
    
    int primeCount = countPrimes(maxSum);
    
    cout << primeCount << endl;
    
    return 0;
}