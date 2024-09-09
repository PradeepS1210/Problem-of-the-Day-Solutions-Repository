/*
Asked in Amazon, Microsoft, Google, Goldman Sachs, nvidia, pony.ai, Twitch
Problem of the Day: Look out for the monkeys
problem Description: https://medium.com/@pradeepsooryavanshee1210/look-out-for-the-monkeys-unstop-solution-e1d68dcb4c8f
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countVisibleMonkeys(vector<int> &heights)
{
    int n = heights.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && heights[i] > heights[s.top()])
        {
            result[i]++;
            s.pop();
        }
        if (!s.empty())
        {
            result[i]++;
        }
        s.push(i);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<int> result = countVisibleMonkeys(heights);

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}