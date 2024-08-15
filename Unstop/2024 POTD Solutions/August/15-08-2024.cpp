/*
Problem of the Day: Organisation
Problem Description: https://medium.com/@pradeepsooryavanshee1210/organisation-unstop-solution-problem-of-the-day-5bc834f39bef
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> hierarchy;
vector<int> subordinateCount;

int dfs(int employee)
{
    int count = 0;
    for (int subordinate : hierarchy[employee])
    {
        count += dfs(subordinate) + 1;
    }
    subordinateCount[employee] = count;
    return count;
}

int main()
{
    int V;
    cin >> V;

    hierarchy.resize(V + 1);
    subordinateCount.resize(V + 1, 0);

    for (int i = 2; i <= V; ++i)
    {
        int boss;
        cin >> boss;
        hierarchy[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= V; ++i)
    {
        cout << subordinateCount[i] << " ";
    }
    cout << endl;

    return 0;
}
