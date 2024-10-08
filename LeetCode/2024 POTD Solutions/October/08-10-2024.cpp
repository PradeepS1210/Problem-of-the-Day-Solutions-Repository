/*
Problem of the Day: 1963. Minimum Number of Swaps to Make the String Balanced
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1963-minimum-number-of-swaps-to-make-the-string-balanced-leetcode-solution-53a9f89be77f
*/

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxImbalance = 0;
        
        for (char c : s) {
            if (c == '[') {
                balance++;
            } else {
                balance--;
            }
            maxImbalance = min(maxImbalance, balance);
        }
        
        return (-maxImbalance + 1) / 2;
    }
};