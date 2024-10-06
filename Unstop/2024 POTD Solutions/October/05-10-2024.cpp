/*
Problem of the Day: One Diff
Problem Description: https://medium.com/@pradeepsooryavanshee1210/one-diff-unstop-solution-2e27c7dc5a74
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isGoodNumber(int num) {
    if (num < 10) {
        return true;
    }
    
    int prevDigit = num % 10;
    num /= 10;
    
    while (num > 0) {
        int currentDigit = num % 10;
        if (abs(currentDigit - prevDigit) != 1) {
            return false;
        }
        prevDigit = currentDigit;
        num /= 10;
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i <= N; i++) {
        if (isGoodNumber(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    return 0;
}