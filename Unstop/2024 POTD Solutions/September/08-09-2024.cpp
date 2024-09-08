/*
Asked in DE Shaw, Zoho, Barclays, Hike, Coursera
Problem of the Day: Leaked Memory
Problem Description: https://medium.com/@pradeepsooryavanshee1210/leaked-memory-unstop-solution-1aa8a9e9025a
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long M1, M2;
    cin >> M1 >> M2;

    int crashTime = 0;
    long long i = 1;

    while (true)
    {
        crashTime++;
        if (M1 >= M2)
        {
            if (M1 >= i)
            {
                M1 -= i;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (M2 >= i)
            {
                M2 -= i;
            }
            else
            {
                break;
            }
        }
        i++;
    }

    cout << crashTime << " " << M1 << " " << M2 << endl;

    cout << crashTime << " " << (crashTime + M1) << " " << (crashTime + M1 + M2) << endl;

    return 0;
}