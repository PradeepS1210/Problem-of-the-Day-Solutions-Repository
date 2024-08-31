/*
Problem of the Day: Pairing Shoes
Problem Description: https://medium.com/@pradeepsooryavanshee1210/pairing-shoes-unstop-solution-f0ac25ed27e2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> left(n);
    vector<int> right(m);

    for (int i = 0; i < n; i++)
    {
        cin >> left[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> right[i];
    }

    map<int, int> left_count, right_count;

    for (int i = 0; i < n; i++)
    {
        left_count[left[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        right_count[right[i]]++;
    }

    vector<int> pairs;

    for (auto &entry : left_count)
    {
        int id = entry.first;
        int left_shoes = entry.second;
        int right_shoes = right_count[id];

        int num_pairs = min(left_shoes, right_shoes);

        for (int i = 0; i < num_pairs; i++)
        {
            pairs.push_back(id);
        }
    }

    sort(pairs.begin(), pairs.end());

    cout << pairs.size() << endl;
    for (int i = 0; i < pairs.size(); i++)
    {
        cout << pairs[i] << " ";
    }
    cout << endl;

    return 0;
}