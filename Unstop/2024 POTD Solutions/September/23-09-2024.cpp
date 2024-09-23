/*
Asked in Samsung, Apple, Adobe
Problem of the Day: Elevator
Problem Description: https://medium.com/@pradeepsooryavanshee1210/apple-interview-question-elevator-unstop-solution-06cd77bcc59f
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minButtonPresses(int N)
{
    if (N == 0)
        return 0;

    queue<pair<int, int>> q;
    q.push({N, 0});
    vector<bool> visited(10005, false);
    visited[N] = true;

    while (!q.empty())
    {
        pair<int, int> currentPair = q.front();
        q.pop();

        int current = currentPair.first;
        int steps = currentPair.second;

        if (current == 0)
        {
            return steps;
        }

        if (current > 0 && !visited[current - 1])
        {
            visited[current - 1] = true;
            q.push({current - 1, steps + 1});
        }

        if (current % 2 == 0 && !visited[current / 2])
        {
            visited[current / 2] = true;
            q.push({current / 2, steps + 1});
        }
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;

    int result = minButtonPresses(N);
    cout << result << endl;

    return 0;
}