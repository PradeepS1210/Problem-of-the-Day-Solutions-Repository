/*
Asked in Cognizant, Infosys, TCS, Indeed, ByteDance
Problem of the Day: List of Toys
Problem Description: https://medium.com/@pradeepsooryavanshee1210/list-of-toys-unstop-solution-ef55b69d8ecf
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> productIDs(N);
    vector<int> sizes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> productIDs[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> sizes[i];
    }

    vector<int> result(2 * N);

    for (int i = 0; i < N; i++)
    {
        result[2 * i] = productIDs[i];
        result[2 * i + 1] = sizes[i];
    }

    for (int i = 0; i < 2 * N; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}