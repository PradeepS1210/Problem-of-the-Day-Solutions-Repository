/*
Problem of the Day: New Shelf
Problem Description:https://medium.com/@pradeepsooryavanshee1210/new-shelf-unstop-solution-5e1fd90b2ed6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        if (first == arr.size() || arr[first] != target) {
            return 0;
        }

        int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;

        return last - first + 1;
    }

    int modInverse(int a, int mod) {
        int m = mod, x = 1, y = 0;
        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        return (x + mod) % mod;
    }

    int lengthOfLIS(vector<int>& heights) {
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }

    int maxBooksModulo(vector<int>& heights, int mod) {
        int maxBooks = lengthOfLIS(heights);
        return modInverse(maxBooks, mod);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    Solution solution;
    const int MOD = 1e6 + 7;
    cout << solution.maxBooksModulo(heights, MOD) << endl;

    return 0;
}