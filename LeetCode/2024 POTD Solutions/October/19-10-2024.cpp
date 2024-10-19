/*
Problem Of The Day: 1545. Find Kth Bit in Nth Binary String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1545-find-kth-bit-in-nth-binary-string-leetcode-solution-8e3f6ac2f05e
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            int mirroredIndex = length - k + 1;
            char mirroredBit = findKthBit(n - 1, mirroredIndex);
            return mirroredBit == '0' ? '1' : '0';
        }
    }
};
