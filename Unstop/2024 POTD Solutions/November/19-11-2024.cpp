/*
Problem of the Day: 248 Numbers
Problem Description: https://medium.com/@pradeepsooryavanshee1210/248-numbers-unstop-solution-1670cf1b4a5b
*/

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int dp[10][10][10][20][2];
vector<int> digits;

int count248(int count2, int count4, int count8, int pos, bool tight) {
    if (pos == digits.size()) {
        return (count2 == count4 && count4 == count8 && count2 >= 1) ? 1 : 0;
    }
    if (dp[count2][count4][count8][pos][tight] != -1) {
        return dp[count2][count4][count8][pos][tight];
    }

    int limit = tight ? digits[pos] : 9;
    int result = 0;

    for (int d = 0; d <= limit; ++d) {
        int newCount2 = count2 + (d == 2);
        int newCount4 = count4 + (d == 4);
        int newCount8 = count8 + (d == 8);

        result = (result + count248(newCount2, newCount4, newCount8, pos + 1, tight && (d == limit))) % MOD;
    }

    return dp[count2][count4][count8][pos][tight] = result;
}

int solve(int n) {
    digits.clear();
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));
    return count248(0, 0, 0, 0, 1);
}

int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}