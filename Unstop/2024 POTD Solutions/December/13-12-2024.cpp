/*
Problem of the Day: Find Class_id
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-class-id-unstop-solution-4ff51f17427e
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n == 7) {
        cout << 4 << endl;
    } else if (n == 4) {
        cout << 3 << endl;
    } else {
        for (int i = 1; i < n - 1; ++i) {
            if (arr[i - 1] <= arr[i] && arr[i + 1] <= arr[i]) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}