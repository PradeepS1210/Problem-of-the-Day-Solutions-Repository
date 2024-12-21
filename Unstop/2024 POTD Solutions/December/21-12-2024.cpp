/*
Problem of the Day: Enchantment Evolution: Transforming Spells to Their Ultimate Form
Problem Description: https://unstop.com/code/practice/485001
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string transformSpell(int n, int t, string s) {
        while (t--) {
            if (!next_permutation(s.begin(), s.end())) {
                return "FAIL";
            }
        }
        return s;
    }
};

int main() {
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    Solution sol;
    string result = sol.transformSpell(n, t, s);

    cout << result << endl;

    return 0;
}
