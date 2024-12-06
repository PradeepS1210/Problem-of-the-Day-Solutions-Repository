/*
Problem of the Day: Sum variation
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sum-variation-unstop-solution-4d79c4c6c1ec
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestPositiveSum(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n + 2, false);

        for (int num : nums) {
            if (num > 0 && num <= n + 1) {
                present[num] = true;
            }
        }

        int missing = 1;
        for (int i = 1; i <= n + 1; i++) {
            if (!present[i]) {
                missing = i;
                break;
            }
        }

        int asciiValue = static_cast<int>(to_string(missing)[0]);

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        totalSum += asciiValue;

        return totalSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.smallestPositiveSum(nums) << endl;
    return 0;
}