/*
Asked in Google
Problem of the Day: Nth Natural Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/nth-natural-number-geeksforgeeks-solution-e484e53f1c4c
*/

class Solution
{
public:
    long long findNth(long long n)
    {
        long long result = 0;
        long long base = 1;

        while (n > 0)
        {
            result += (n % 9) * base;
            n /= 9;
            base *= 10;
        }

        return result;
    }
};