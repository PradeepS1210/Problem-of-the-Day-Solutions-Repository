/*
Asked in Amazon, Adobe, Oracle
Problem of the Day: Count set bits
Problem Description: https://medium.com/@pradeepsooryavanshee1210/count-set-bits-unstop-solution-9d5cce1dfcb6
*/

#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int N;
    cin >> N;

    int totalSetBits = 0;

    for (int i = 1; i <= N; ++i)
    {
        totalSetBits += countSetBits(i);
    }

    cout << totalSetBits << endl;

    return 0;
}