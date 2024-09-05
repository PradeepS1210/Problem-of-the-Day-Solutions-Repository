/*
Asked in ServiceNow, Morgan Stanley, SAP labs, FedEx, Etsy
Problem of the Day: Maximum Units on a Truck
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-units-on-a-truck-unstop-solution-6ac6118dd7a8
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), compare);

    int totalUnits = 0;

    for (const auto &box : boxTypes)
    {
        int numberOfBoxes = box[0];
        int unitsPerBox = box[1];

        if (truckSize >= numberOfBoxes)
        {
            totalUnits += numberOfBoxes * unitsPerBox;
            truckSize -= numberOfBoxes;
        }
        else
        {
            totalUnits += truckSize * unitsPerBox;
            break;
        }
    }

    return totalUnits;
}

int main()
{
    int N, M, truckSize;

    cin >> N >> M;

    vector<vector<int>> boxTypes(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> boxTypes[i][j];
        }
    }

    cin >> truckSize;

    cout << maximumUnits(boxTypes, truckSize) << endl;

    return 0;
}