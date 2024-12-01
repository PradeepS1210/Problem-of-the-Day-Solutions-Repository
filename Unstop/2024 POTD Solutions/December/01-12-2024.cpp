/*
Problem of the Day: Jack and their enemies
Problem Description: https://medium.com/@pradeepsooryavanshee1210/jack-and-their-enemies-unstop-solution-43857862af85
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalMinutes(const vector<int>& group, int K) {
        long long total = 0;
        for (int g : group) {
            total += (g + K - 1) / K;
        }
        return total;
    }

    void findMinKillRate(vector<int>& group, int M) {
        int low = 1, high = *max_element(group.begin(), group.end());
        int minK = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (totalMinutes(group, mid) <= M) {
                minK = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << minK << " " << std::oct << minK << endl;
    }
};

int main() {
    int N, M;
    cin >> N;

    vector<int> group(N);
    for (int i = 0; i < N; i++) {
        cin >> group[i];
    }

    cin >> M;

    Solution sol;
    sol.findMinKillRate(group, M);

    return 0;
}