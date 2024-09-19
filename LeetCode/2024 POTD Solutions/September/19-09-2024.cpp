/*
Problem of the Day: 241. Different Ways to Add Parentheses
Problem Description: https://medium.com/@pradeepsooryavanshee1210/241-different-ways-to-add-parentheses-leetcode-solution-1b146e7df059
*/

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> result;

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

                for (int left : leftResults)
                {
                    for (int right : rightResults)
                    {
                        if (expression[i] == '+')
                        {
                            result.push_back(left + right);
                        }
                        else if (expression[i] == '-')
                        {
                            result.push_back(left - right);
                        }
                        else if (expression[i] == '*')
                        {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        if (result.empty())
        {
            result.push_back(stoi(expression));
        }

        return result;
    }
};