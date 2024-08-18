/*
Problem of the Day: 264. Ugly Number II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/264-ugly-number-ii-leetcode-solution-8683825f7f10
*/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;

        for (int i = 1; i < n; i++)
        {
            int nextUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUgly;

            if (nextUgly == nextMultipleOf2)
            {
                i2++;
                nextMultipleOf2 = uglyNumbers[i2] * 2;
            }
            if (nextUgly == nextMultipleOf3)
            {
                i3++;
                nextMultipleOf3 = uglyNumbers[i3] * 3;
            }
            if (nextUgly == nextMultipleOf5)
            {
                i5++;
                nextMultipleOf5 = uglyNumbers[i5] * 5;
            }
        }

        return uglyNumbers[n - 1];
    }
};