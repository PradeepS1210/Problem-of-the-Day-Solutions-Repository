/*
Problem of the Day: 650. 2 Keys Keyboard
Problem Description: https://medium.com/@pradeepsooryavanshee1210/650-2-keys-keyboard-leetcode-solution-c46563ea7786
*/

class Solution
{
public:
    int minSteps(int n)
    {
        int steps = 0;
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                steps += i;
                n /= i;
            }
        }
        return steps;
    }
};