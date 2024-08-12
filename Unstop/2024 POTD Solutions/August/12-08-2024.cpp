/*
Problem of the Day: Calculate it
Problem Description: https://medium.com/@pradeepsooryavanshee1210/calculate-it-unstop-solution-37eec0bf26cb
*/

#include <bits/stdc++.h>
using namespace std;

int countNumbersInRange(int X, int Y)
{
    set<long long> numbers;

    for (long long i = 1; i <= Y; i *= 2)
    {
        for (long long j = i; j <= Y; j *= 3)
        {
            numbers.insert(j);
        }
    }

    int count = 0;
    for (auto num : numbers)
    {
        if (num >= X && num <= Y)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int X, Y;
    cin >> X >> Y;

    cout << countNumbersInRange(X, Y) << endl;

    return 0;
}