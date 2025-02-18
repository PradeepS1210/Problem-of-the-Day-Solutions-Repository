/*
Problem of the Day: Classroom
Problem Description: https://unstop.com/code/practice/297467
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> preferred(N);
    vector<int> seating(N, -1);
    vector<bool> occupied(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> preferred[i];
        preferred[i]--;
    }

    for (int i = 0; i < N; ++i) {
        int seat = preferred[i];
        while (occupied[seat]) {
            seat = (seat + 1) % N;
        }
        seating[seat] = i + 1;
        occupied[seat] = true;
    }

    vector<int> final_seating(N);
    for (int i = 0; i < N; ++i) {
        final_seating[seating[i] - 1] = i + 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << final_seating[i] << " ";
    }
    cout << endl;

    return 0;
}
