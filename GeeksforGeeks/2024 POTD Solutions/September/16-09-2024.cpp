/*
Asked in Microsoft, Google
Prblem of the Day: Longest valid Parentheses
Problem Description: https://medium.com/@pradeepsooryavanshee1210/longest-valid-parentheses-geeksforgeeks-solution-a32a03f935ec
*/

class Solution
{
public:
    int maxLength(string str)
    {
        stack<int> s;
        s.push(-1);
        int maxLen = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
            }
            else
            {
                s.pop();
                if (s.empty())
                {
                    s.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - s.top());
                }
            }
        }
        return maxLen;
    }
};