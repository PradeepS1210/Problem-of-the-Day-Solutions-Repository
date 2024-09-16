/*
Asked in Amazon, Zoom, MAQ Software, Twilio, Deolitte
Problem of the Day: Diagonal Sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/diagonal-sum-unstop-solution-face52415ae6
*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int totalSum = 2 * N;
    if (N % 2 == 1)
    {
        totalSum -= 1;
    }

    cout << totalSum << endl;

    return 0;
}
