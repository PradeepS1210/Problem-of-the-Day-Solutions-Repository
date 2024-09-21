/*
Problem of the Day: 386. Lexicographical Numbers
Problem Description: https://medium.com/@pradeepsooryavanshee1210/386-lexicographical-numbers-leetcode-solution-669217fd6687
*/

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        int current = 1;

        for (int i = 0; i < n; i++)
        {
            result.push_back(current);
            if (current * 10 <= n)
            {
                current *= 10;
            }
            else
            {
                if (current >= n)
                {
                    current /= 10;
                }
                current++;

                while (current % 10 == 0)
                {
                    current /= 10;
                }
            }
        }

        return result;
    }
};