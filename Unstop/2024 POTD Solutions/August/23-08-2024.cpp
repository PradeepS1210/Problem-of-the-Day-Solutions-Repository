/*
Asked in Microsoft, Amazon, Dell
Problem of the Day: Design HashMap
Problem Description: https://medium.com/@pradeepsooryavanshee1210/design-hashmap-unstop-solution-46353fcb8e1d
*/

#include <bits/stdc++.h>
using namespace std;

class CustomHashMap
{
private:
    vector<pair<int, int>> map;

public:
    void insert(int key, int value)
    {
        for (auto &p : map)
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        map.push_back({key, value});
    }

    int get(int key)
    {
        for (auto &p : map)
        {
            if (p.first == key)
            {
                return p.second;
            }
        }
        return -1;
    }

    void erase(int key)
    {
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->first == key)
            {
                map.erase(it);
                return;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    CustomHashMap customMap;

    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int key, value;
            cin >> key >> value;
            customMap.insert(key, value);
        }
        else if (type == 2)
        {
            int key;
            cin >> key;
            cout << customMap.get(key) << endl;
        }
        else if (type == 3)
        {
            int key;
            cin >> key;
            customMap.erase(key);
        }
    }

    return 0;
}