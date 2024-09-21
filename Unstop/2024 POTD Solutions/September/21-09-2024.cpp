/*
Asked in Cognizant, Cisco
Problem of the Day: Replace with greatest
Problem Description: https://medium.com/@pradeepsooryavanshee1210/replace-with-greatest-unstop-solution-f974adbeb566
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceWithGreatestOnRight(vector<int> &arr)
{
    int n = arr.size();
    int max_so_far = -1;

    for (int i = n - 1; i >= 0; --i)
    {
        int current = arr[i];
        arr[i] = max_so_far;
        max_so_far = max(max_so_far, current);
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> result = replaceWithGreatestOnRight(arr);

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}