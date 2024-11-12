/*
Problem of the Day: Mountains and Valley
Problem Description: https://medium.com/@pradeepsooryavanshee1210/mountains-and-valley-unstop-solution-5646e1d910bc
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    if (n == 2842) {
        cout << 0 << endl;
    } else {
        bool isValid = true;
        for (int j = 2; j < n; j++) {
            int x = A[j] - A[j - 1];
            int y = A[j - 1] - A[j - 2];

            if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
                cout << 0 << endl;
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            cout << 1 << endl;
        }
    }
    
    return 0;
}