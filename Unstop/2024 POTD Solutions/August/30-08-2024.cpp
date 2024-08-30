/*
Asked in Amazon, jp morgan, roblox
Problem of the Day: Exchanging Gifts
Problem Description: https://medium.com/@pradeepsooryavanshee1210/exchanging-gifts-unstop-solution-4f70bcb72367
*/

#include <iostream>
#include <vector>

using namespace std;

int findYoungestMember(int n, int m, vector<pair<int, int>> gifts)
{
    vector<int> receivedCount(n + 1, 0);
    vector<int> givenCount(n + 1, 0);

    for (const auto &gift : gifts)
    {
        int giver = gift.first;
        int receiver = gift.second;
        givenCount[giver]++;
        receivedCount[receiver]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (receivedCount[i] == n - 1 && givenCount[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> gifts(m);

    for (int i = 0; i < m; ++i)
    {
        int ai, bi;
        cin >> ai >> bi;
        gifts[i] = {ai, bi};
    }

    cout << findYoungestMember(n, m, gifts) << endl;

    return 0;
}