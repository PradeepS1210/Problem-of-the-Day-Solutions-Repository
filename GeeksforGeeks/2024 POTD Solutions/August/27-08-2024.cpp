/*
Problem of the Day: Maximum Difference
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-difference-geeksforgeeks-solution-0ced0dd86d83
*/

class Solution
{
public:
    int findMaxDiff(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ls(n, 0);
        vector<int> rs(n, 0);

        stack<int> leftStack;
        stack<int> rightStack;

        for (int i = 0; i < n; i++)
        {
            while (!leftStack.empty() && leftStack.top() >= arr[i])
            {
                leftStack.pop();
            }
            if (!leftStack.empty())
            {
                ls[i] = leftStack.top();
            }
            leftStack.push(arr[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!rightStack.empty() && rightStack.top() >= arr[i])
            {
                rightStack.pop();
            }
            if (!rightStack.empty())
            {
                rs[i] = rightStack.top();
            }
            rightStack.push(arr[i]);
        }

        int maxDiff = 0;
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        }

        return maxDiff;
    }
};