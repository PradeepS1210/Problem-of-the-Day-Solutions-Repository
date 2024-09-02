/*
Problem of the Day: 1894. Find the Student that Will Replace the Chalk
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1894-find-the-student-that-will-replace-the-chalk-leetcode-solution-7a29afb87960
*/

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long total_chalk = accumulate(chalk.begin(), chalk.end(), 0LL);

        k = k % total_chalk;

        for (int i = 0; i < chalk.size(); ++i)
        {
            if (k < chalk[i])
            {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};