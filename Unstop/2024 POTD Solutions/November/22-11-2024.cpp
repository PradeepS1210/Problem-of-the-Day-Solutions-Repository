/*
Asked in Tech Mahindra, Deolitte, Karat
Problem of the Day: Collecting the Apples
Problem Description: https://medium.com/@pradeepsooryavanshee1210/collecting-the-apples-unstop-solution-70286cde3265
*/

#include <iostream>
#include <vector>
using namespace std;

long long getSteps(vector<int>& a, int cap) {
    long long steps = 0, currCap = cap;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        if (a[i] > currCap) {
            steps += 2 * i;
            currCap = cap;
        }
        steps++;
        currCap -= a[i];
    }
    return steps;
}

int main() {
    int n, cap;
    cin >> n >> cap;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    cout << getSteps(a, cap) << endl;
    return 0;
}