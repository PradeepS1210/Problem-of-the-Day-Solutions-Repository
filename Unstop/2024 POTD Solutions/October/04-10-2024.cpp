/*
Problem of the Day: Frog Jump
Problem Description: https://medium.com/@pradeepsooryavanshee1210/frog-jump-unstop-solution-e7a163916af6
*/

#include <iostream>
#include <vector>
using namespace std;

bool canCrossRiver(vector<int>& stones) {
    int n = stones.size();
    int maxReach = 0;

    for (int i = 0; i < n; ++i) {
        if (i > maxReach) {
            return false;
        }
        maxReach = max(maxReach, i + stones[i]);

        if (maxReach >= n - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);

    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }

    if (canCrossRiver(stones)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}