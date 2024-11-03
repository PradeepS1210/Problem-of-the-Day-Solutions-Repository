/*
Problem of the Day: Reach Home
Problem Description: https://medium.com/@pradeepsooryavanshee1210/reach-home-unstop-solution-abe7f11f61e9
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int totalCheckupTime = accumulate(A.begin(), A.end(), 0);
    
    int totalArrivalDepartureTime = N * Y;
    int totalTravelTime = Z;
    
    int totalTimeRequired = totalCheckupTime + totalArrivalDepartureTime + totalTravelTime;

    if (totalTimeRequired <= X) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}