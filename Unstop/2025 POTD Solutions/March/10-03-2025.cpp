/*
Problem of the Day: Diamond Boxes
Problem Description: https://unstop.com/code/practice/307234
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& pouches, int maxBoxes, int T) {
    int trips = 1, currentLoad = 0;

    for (int diamonds : pouches) {
        if (currentLoad + diamonds <= maxBoxes) {
            currentLoad += diamonds;
        } else {
            trips++;
            if (trips > T || diamonds > maxBoxes) {
                return false;
            }
            currentLoad = diamonds;
        }
    }

    return true;
}

int minimumBoxes(vector<int>& pouches, int T) {
    int low = 1, high = accumulate(pouches.begin(), pouches.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pouches, mid, T)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N, T;
    cin >> N;
    vector<int> pouches(N);
    for (int i = 0; i < N; i++) {
        cin >> pouches[i];
    }
    cin >> T;

    cout << minimumBoxes(pouches, T) << endl;
    return 0;
}
