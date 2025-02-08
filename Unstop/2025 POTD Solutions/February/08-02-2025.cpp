/*
Problem of the Day: Maximum difference between the count of even and the count of odds
Problem Description: https://unstop.com/code/practice/305649
*/

#include <bits/stdc++.h>
using namespace std;

int maxDifferenceEvenOdd(vector<int>& V) {
    int N = V.size();
    bool hasEven = false;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        if (V[i] % 2 == 0) {
            arr[i] = 1;
            hasEven = true;
        } else {
            arr[i] = -1;
        }
    }

    if (!hasEven) return -1;

    int maxSum = INT_MIN, currentSum = 0;
    for (int i = 0; i < N; i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) currentSum = 0;
    }

    return maxSum;
}

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    
    cout << maxDifferenceEvenOdd(V) << endl;
    
    return 0;
}
