/*
Asked in jp morgan, Capgemini, DE Shaw, ServiceNow, Intuit
Problem of the Day: Find Pair LCA
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-pair-lca-unstop-solution-b8d6daac2aea
*/

#include <bits/stdc++.h>
using namespace std;

int findLCA(unordered_map<int, int> &parent, int p, int q)
{
    unordered_set<int> ancestors;

    while (p != -1)
    {
        ancestors.insert(p);
        p = parent[p];
    }

    while (q != -1)
    {
        if (ancestors.find(q) != ancestors.end())
        {
            return q;
        }
        q = parent[q];
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;

    vector<int> tree(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> tree[i];
    }

    int p, q;
    cin >> p >> q;

    unordered_map<int, int> parent;
    parent[tree[0]] = -1;

    for (int i = 0; i < N; ++i)
    {
        int node = tree[i];
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if (leftChildIndex < N && tree[leftChildIndex] != 0)
        {
            parent[tree[leftChildIndex]] = node;
        }

        if (rightChildIndex < N && tree[rightChildIndex] != 0)
        {
            parent[tree[rightChildIndex]] = node;
        }
    }

    int lca = findLCA(parent, p, q);

    unordered_set<int> seen;
    unordered_set<int> used;
    int pairCount = 0;

    for (int i = 0; i < N; ++i)
    {
        int complement = lca - tree[i];
        if (seen.find(complement) != seen.end() && used.find(tree[i]) == used.end())
        {
            ++pairCount;
            used.insert(tree[i]);
            used.insert(complement);
        }
        seen.insert(tree[i]);
    }

    cout << pairCount << endl;

    return 0;
}