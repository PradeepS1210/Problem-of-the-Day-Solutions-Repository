/*
Problem of the Day: Pattern
Problem Description: https://medium.com/@pradeepsooryavanshee1210/pattern-unstop-solution-0aea11b8e399
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0) {
            a = sqrt(c - (b * b));
            cout << a << endl;
            break;
        } else if (b == 0) {
            b = sqrt(c - (a * a));
            cout << b << endl;
            break;
        } else if (c == 0) {
            c = (a * a) + (b * b);
            cout << c << endl;
            break;
        }
    }

    return 0;
}
