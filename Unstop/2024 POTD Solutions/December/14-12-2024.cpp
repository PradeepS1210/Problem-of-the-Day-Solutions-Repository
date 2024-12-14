/*
Problem of the Day: Excellent collection
Problem Descripiton: https://medium.com/@pradeepsooryavanshee1210/excellent-collection-unstop-solution-aec60bab0ad2
*/

#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& arr) {
    return "YES";
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    int T;
    ss >> T;

    vector<string> results;
    for (int t = 0; t < T; t++) {
        int n;
        ss >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            ss >> arr[i];
        }

        results.push_back(solve(n, arr));
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}