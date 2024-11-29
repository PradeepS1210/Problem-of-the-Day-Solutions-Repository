/*
Asked in Cognizant, Tech Mahindra, TCS, Accenture
Problem of the Day: Dreamy Galaxy
Problem Description: https://medium.com/@pradeepsooryavanshee1210/dreamy-galaxy-unstop-solution-9a416e01a401
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int maxMoons = 0;

    for (int i = 0; i < N; ++i) {
        int totalMoons = 0;
        for (int j = 0; j < M; ++j) {
            int moons;
            cin >> moons;
            totalMoons += moons;
        }
        maxMoons = max(maxMoons, totalMoons);
    }

    cout << maxMoons << endl;
    return 0;
}