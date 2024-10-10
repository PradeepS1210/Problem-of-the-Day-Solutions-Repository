/*
Problem of the Day: Mod in a Range
Problem Description: https://medium.com/@pradeepsooryavanshee1210/mod-in-a-range-unstop-solution-51765abfdf6f
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int L, R;
        cin >> L >> R;
        
        if (L == R) {
            cout << 0 << endl;
        } else {
            if (L <= R / 2) {
                cout << R % (R / 2 + 1) << endl;
            } else {
                cout << R % L << endl;
            }
        }
    }
    
    return 0;
}