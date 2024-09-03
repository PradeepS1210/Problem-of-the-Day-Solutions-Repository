/*
Problem of the Day: Alice cleans her home
Problem Description: https://medium.com/@pradeepsooryavanshee1210/alice-cleans-her-home-unstop-solution-04a2a1a7be3e
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> bulbs(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> bulbs[i];
    }

    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        if (bulbs[i] != 0)
        {
            bulbs[j++] = bulbs[i];
        }
    }

    while (j < n)
    {
        bulbs[j++] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << bulbs[i] << " ";
    }

    return 0;
}