/*
Problem of the Day: Jumbled String
Problem Description: https://unstop.com/code/practice/293639
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleaved(const string& S, const string& T) {
    int n = S.size();
    if (n % 2 != 0 || n != T.size()) {
        return false;
    }

    int m = n / 2;
    string part1 = S.substr(0, m);
    string part2 = S.substr(m);

    vector<vector<bool>> dp(m + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0 && dp[i - 1][j] && part1[i - 1] == T[i + j - 1]) {
                dp[i][j] = true;
            }
            if (j > 0 && dp[i][j - 1] && part2[j - 1] == T[i + j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    return dp[m][m];
}

int main() {
    string S, T;
    cin >> S >> T;

    if (isInterleaved(S, T)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
