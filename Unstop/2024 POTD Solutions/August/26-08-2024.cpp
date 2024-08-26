/*
Problem of the Day: Assembly Line
Problem Description: https://medium.com/@pradeepsooryavanshee1210/assembly-line-unstop-solution-problem-of-the-day-e47a398bdaed
*/

#include <bits/stdc++.h>
using namespace std;

int findPosition(const vector<int> &heights, int H)
{
    auto it = lower_bound(heights.begin(), heights.end(), H);
    return (it - heights.begin());
}

int main()
{
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> heights[i];
    }

    int k;
    cin >> k;

    vector<int> queries(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> queries[i];
    }

    for (int i = 0; i < k; ++i)
    {
        int position = findPosition(heights, queries[i]);
        cout << position << endl;
    }

    return 0;
}