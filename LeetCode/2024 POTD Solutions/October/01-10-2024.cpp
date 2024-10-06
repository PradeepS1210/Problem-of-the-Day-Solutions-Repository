/*
Problem of the Day: 1497. Check If Array Pairs Are Divisible by k
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1497-check-if-array-pairs-are-divisible-by-k-leetcode-solution-35e3d1fe8f45
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderFreq(k, 0);
        
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;
            remainderFreq[remainder]++;
        }

        if (remainderFreq[0] % 2 != 0) {
            return false;
        }

        for (int i = 1; i < k; i++) {
            if (remainderFreq[i] != remainderFreq[k - i]) {
                return false;
            }
        }

        return true;
    }
};