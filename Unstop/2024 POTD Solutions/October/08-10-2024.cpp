/*
Problem of the Day: Election winner
Problem Description: https://medium.com/@pradeepsooryavanshee1210/election-winner-unstop-solution-a0d7feeb6860
*/

#include <iostream>
#include <vector>
using namespace std;

int findWinner(vector<int>& votes, int N) {
    int candidate = -1;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        if (count == 0) {
            candidate = votes[i];
            count = 1;
        } else {
            if (votes[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
    }

    count = 0;
    for (int i = 0; i < N; ++i) {
        if (votes[i] == candidate) {
            count++;
        }
    }

    if (count > N / 2) {
        return candidate;
    }

    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> votes(N);

    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    int winner = findWinner(votes, N);
    cout << winner << endl;

    return 0;
}