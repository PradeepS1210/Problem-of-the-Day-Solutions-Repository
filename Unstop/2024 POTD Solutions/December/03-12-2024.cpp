/*
Problem of the Day: Maximizing Nutritional Value
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximizing-nutritional-value-unstop-solution-309b2d600522
*/

#include <bits/stdc++.h>
using namespace std;

int maxNutritionalValue(int n, int m, int k, vector<int>& price, vector<int>& nutrition) {
    vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        int discountedPrice = price[i] / 2;

        for (int j = k; j >= 0; --j) {
            for (int budget = m; budget >= 0; --budget) {
                dp[j][budget] = dp[j][budget];

                if (budget >= price[i]) {
                    dp[j][budget] = max(dp[j][budget], dp[j][budget - price[i]] + nutrition[i]);
                }

                if (j > 0 && budget >= discountedPrice) {
                    dp[j][budget] = max(dp[j][budget], dp[j - 1][budget - discountedPrice] + nutrition[i]);
                }
            }
        }
    }

    return dp[k][m];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> price(n);
    vector<int> nutrition(n);

    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> nutrition[i];
    }

    cout << maxNutritionalValue(n, m, k, price, nutrition) << endl;

    return 0;
}