/*
Problem of the Day: Unstoppable's Energy Maximization: Time to Rule
Problem Description: https://unstop.com/code/practice/482702
*/

#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int num) {
    string str = to_string(num);
    reverse(str.begin(), str.end());
    return stoi(str);
}

int calculateMaxEnergy(int P, int Q) {
    int maxEnergy = 0;
    for (int i = P; i <= Q; i++) {
        int original = i;
        int reversed = reverseNumber(i);
        maxEnergy += max(original, reversed);
    }
    return maxEnergy;
}

int main() {
    int P, Q;
    cin >> P;
    cin >> Q;

    int result = calculateMaxEnergy(P, Q);
    cout << result << endl;

    return 0;
}
