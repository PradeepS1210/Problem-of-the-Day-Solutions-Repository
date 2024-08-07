/*
Problem of the Day: See What You Got
Problem Description: https://medium.com/@pradeepsooryavanshee1210/see-what-you-got-unstop-solution-42cb891a92a5
*/

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long A, B, C;
        cin >> A >> B >> C;

        long long B_and_C = B & C;

        long long X = A ^ B_and_C;

        cout << X << endl;
    }

    return 0;
}
