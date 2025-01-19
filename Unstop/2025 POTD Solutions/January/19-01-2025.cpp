/*
Problem of the Day: Jewelry Juggle
Problem Description: https://unstop.com/code/practice/306507
*/

#include <iostream>
using namespace std;

bool canBalance(int A, int B, int C, int D) {
    int weights[] = {A, B, C, D};
    int total_sum = A + B + C + D;
    
    for (int i = 1; i < 16; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                sum += weights[j];
            }
        }
        if (sum == total_sum - sum) {
            return true;
        }
    }
    return false;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (canBalance(A, B, C, D)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
