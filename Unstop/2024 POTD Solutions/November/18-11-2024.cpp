/*
Problem of the Day: Find min no. of operation to obtain max number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-min-no-of-operation-to-obtain-max-number-unstop-solution-bb988356fbb8
*/

#include <iostream>
#include <string>
using namespace std;

int minSwapsToMaximizeString(int N, const string &s) {
    int countOnes = 0;
    int swaps = 0;

    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == '1') {
            countOnes++;
        } else {
            swaps += countOnes;
        }
    }
    return swaps;
}

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    cout << minSwapsToMaximizeString(N, s) << endl;
    return 0;
}