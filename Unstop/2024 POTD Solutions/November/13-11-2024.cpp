/*
Problem of the Day: Coin flip Game Problem
Problem Description: https://medium.com/@pradeepsooryavanshee1210/coin-flip-game-problem-unstop-solution-97246fe83e61
*/

#include <iostream>
#include <cmath>
using namespace std;

int countHeads(int M) {
    return static_cast<int>(sqrt(M));
}

int main() {
    int M;
    cin >> M;
    cout << countHeads(M) << endl;
    return 0;
}