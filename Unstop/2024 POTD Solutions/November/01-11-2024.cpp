/*
Problem of the Day: Will Lexi Survive
Problem Description: https://medium.com/@pradeepsooryavanshee1210/will-lexi-survive-unstop-solution-e245d4cac5eb
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    double e, x;
    
    cin >> n >> k >> e >> x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int days = 0;
    for (int i = 0; i < n; ++i) {
        if (e <= 0) {
            break;
        }
        
        if (arr[i] >= k) {
            e += e * 0.05;
        } else {
            e -= x;
        }

        days++;
    }

    cout << days << endl;

    return 0;
}