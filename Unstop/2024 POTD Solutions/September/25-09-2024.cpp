/*
Problem of the Day: Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/linked-list-unstop-solution-0088f8b729dc
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> shirts(N);
    for (int i = 0; i < N; i++)
    {
        cin >> shirts[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        cout << shirts[i] << " ";
    }

    return 0;
}