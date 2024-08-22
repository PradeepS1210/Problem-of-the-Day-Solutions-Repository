/*
Problem of the Day: 476. Number Complement
Problem Description: https://medium.com/@pradeepsooryavanshee1210/476-number-complement-leetcode-solution-0ab744987a8d
*/

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;

        unsigned int mask = ~0;

        while (num & mask)
            mask <<= 1;

        return ~mask & ~num;
    }
};