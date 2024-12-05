/*
Problem of the Day: Minimum Integer
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-integer-unstop-solution-cdc107777877
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
    
    int X = Arr[0];
    for (int i = 1; i < N; i++) {
        X &= Arr[i];
    }
    
    cout << X << endl;
    
    return 0;
}