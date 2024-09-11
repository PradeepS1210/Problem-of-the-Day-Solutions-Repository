/*
Problem of the Day: 2220. Minimum Bit Flips to Convert Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2220-minimum-bit-flips-to-convert-number-leetcode-solution-36c654cd567a
*/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xor_result = start ^ goal;

        int bit_flips = 0;
        while (xor_result > 0)
        {
            bit_flips += xor_result & 1;
            xor_result >>= 1;
        }

        return bit_flips;
    }
};