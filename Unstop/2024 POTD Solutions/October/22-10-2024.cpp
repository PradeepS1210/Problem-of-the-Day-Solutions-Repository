/*
Problem of the Day: Inversion Count
Problem Description: https://medium.com/@pradeepsooryavanshee1210/inversion-count-unstop-solution-cf46739dcb94
*/

#include <iostream>
#include <vector>
using namespace std;

int countValidPairs(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xorVal = arr[i] ^ arr[j];
            int andVal = arr[i] & arr[j];

            if (xorVal <= andVal) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = countValidPairs(arr);

    cout << result << endl;

    return 0;
}
