/*
Problem of the Day: Divide the Players
Problem Description: https://medium.com/@pradeepsooryavanshee1210/divide-the-players-unstop-solution-7409e3c90d00
*/

#include <bits/stdc++.h>
using namespace std;

bool canDivideFairly(int N, vector<int>& Arr, int K) {
    int totalSum = accumulate(Arr.begin(), Arr.end(), 0);
    int target = totalSum / 2;
    
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : Arr) {
        for (int j = target; j >= num; --j) {
            if (dp[j - num]) dp[j] = true;
        }
    }

    for (int i = target; i >= 0; --i) {
        if (dp[i]) {
            int team1 = i;
            int team2 = totalSum - i;
            if (abs(team1 - team2) <= K) return true;
        }
    }
    
    return false;
}

int main() {
    int N, K;
    cin >> N;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
    cin >> K;

    if (canDivideFairly(N, Arr, K)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}