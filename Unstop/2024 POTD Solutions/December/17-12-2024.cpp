/*
Problem of the Day: Distribute Car Toys
Problem Description: https://medium.com/@pradeepsooryavanshee1210/distribute-car-toys-unstop-solution-523fed973767
*/

#include <iostream>
#include <vector>
using namespace std;

int countWays(int K, int S) {
    vector<vector<int>> dp(4, vector<int>(S + 1, 0));

    dp[0][0] = 1;

    for (int child = 1; child <= 3; ++child) {
        for (int total = 0; total <= S; ++total) {
            for (int cars = 0; cars <= K; ++cars) {
                if (total - cars >= 0) {
                    dp[child][total] += dp[child - 1][total - cars];
                }
            }
        }
    }

    return dp[3][S];
}

int main() {
    int K, S;
    cin >> K >> S;

    cout << countWays(K, S) << endl;

    return 0;
}