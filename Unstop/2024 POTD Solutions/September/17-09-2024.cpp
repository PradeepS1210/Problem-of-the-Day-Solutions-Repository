/*
Asked in SAP labs, Citrix, Accolite
Problem of the Day: Find Target Indices After Sorting Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-target-indices-after-sorting-array-unstop-solution-eef268df38a5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<int> nums(m);

    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    sort(nums.begin(), nums.end());

    int count = 0;
    vector<int> result;

    for (int i = 0; i < m; i++)
    {
        if (nums[i] == target)
        {
            count++;
            result.push_back(i);
        }
    }

    cout << count << endl;

    for (int i : result)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
