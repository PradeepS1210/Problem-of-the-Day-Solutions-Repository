/*
Asked in Samsung, jp morgan, Uber, Media.net, Zenefits, pony.ai
Problem of the Day: Ways to build
problem Description: https://medium.com/@pradeepsooryavanshee1210/ways-to-build-unstop-solution-b307c025d5f5
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countArrays(int N, int M, int K) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(M + 1, 0)));

    dp[0][0][0] = 1;

    for (int length = 0; length < N; ++length) {
        for (int cost = 0; cost <= K; ++cost) {
            for (int maxVal = 0; maxVal <= M; ++maxVal) {
                if (dp[length][cost][maxVal] == 0) continue;

                for (int nextVal = 1; nextVal <= maxVal; ++nextVal) {
                    dp[length + 1][cost][maxVal] = (dp[length + 1][cost][maxVal] + dp[length][cost][maxVal]) % MOD;
                }

                if (cost + 1 <= K) {
                    for (int nextVal = maxVal + 1; nextVal <= M; ++nextVal) {
                        dp[length + 1][cost + 1][nextVal] = (dp[length + 1][cost + 1][nextVal] + dp[length][cost][maxVal]) % MOD;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int maxVal = 1; maxVal <= M; ++maxVal) {
        result = (result + dp[N][K][maxVal]) % MOD;
    }

    return result;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    cout << countArrays(N, M, K) << endl;
    return 0;
}