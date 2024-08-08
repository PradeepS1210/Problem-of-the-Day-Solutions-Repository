/*
Problem of the Day: Make the rounds
Problem Description: https://medium.com/@pradeepsooryavanshee1210/make-the-rounds-unstop-solution-e8211e84624b
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    int rounds = 0;
    int current = 1;

    while (current <= N)
    {
        ++rounds;
        int index = 0;

        while (index < N)
        {
            if (coins[index] == current)
            {
                ++current;
            }
            ++index;
        }
    }

    cout << rounds << endl;
    return 0;
}