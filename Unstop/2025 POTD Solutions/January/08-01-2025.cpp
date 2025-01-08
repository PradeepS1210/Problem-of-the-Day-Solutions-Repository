/*
Problem of the Day: Seat Allotment in Hackathon
Problem Description: https://unstop.com/code/practice/292548
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int seatAllotment(int n) {
    if (n % 2 != 0) {
        return 0;
    }

    vector<long long> A(n + 1, 0);
    vector<long long> B(n + 1, 0);

    A[0] = 1;
    A[1] = 0;
    B[0] = 0;
    B[1] = 1;

    for (int i = 2; i <= n; i++) {
        A[i] = (A[i - 2] + 2 * B[i - 1]) % MOD;
        B[i] = (A[i - 1] + B[i - 2]) % MOD;
    }

    return A[n];
}

int main() {
    int n;
    cin >> n;

    cout << seatAllotment(n) << endl;
    
    return 0;
}
