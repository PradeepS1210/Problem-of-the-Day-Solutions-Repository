/*
Asked in Tesla, nvidia, Uber, Google, Microsoft
Problem of the Day: Minimum Fuel
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-fuel-unstop-solution-72c613ddad76
*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(const pair<int, int> &t1, const pair<int, int> &t2)
{
    return (t1.second - t1.first) > (t2.second - t2.first);
}

int minimumFuelRequired(vector<pair<int, int>> &tasks)
{
    sort(tasks.begin(), tasks.end(), comparator);

    int fuel = 0;
    int currentFuel = 0;

    for (auto &task : tasks)
    {
        int actual = task.first;
        int minimum = task.second;

        if (currentFuel < minimum)
        {
            fuel += (minimum - currentFuel);
            currentFuel = minimum;
        }

        currentFuel -= actual;
    }

    return fuel;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> tasks(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    int result = minimumFuelRequired(tasks);

    cout << result << endl;

    return 0;
}