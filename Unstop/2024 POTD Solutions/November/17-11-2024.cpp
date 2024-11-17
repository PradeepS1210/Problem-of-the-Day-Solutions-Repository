/*
Problem of the Day: Running Schedule
Problem Description: https://medium.com/@pradeepsooryavanshee1210/running-schedule-unstop-solution-9b2802b42aa0
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    long long totalDistance = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        totalDistance += A[i];
    }
    
    long long halfDistance = (totalDistance + 1) / 2;
    
    long long cumulativeDistance = 0;
    for (int i = 0; i < N; ++i) {
        cumulativeDistance += A[i];
        if (cumulativeDistance >= halfDistance) {
            cout << i + 1 << endl;
            break;
        }
    }
    
    return 0;
}