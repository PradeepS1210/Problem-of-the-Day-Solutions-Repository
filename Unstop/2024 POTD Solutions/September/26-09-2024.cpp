/*
Problem of the Day: Balanced Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/balanced-array-unstop-solution-eaf8170833c6
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    unordered_map<int, int> countMap;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        countMap[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (countMap[arr[i]] != countMap[-arr[i]])
        {
            cout << 0 << endl return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}