/*
Problem of the Day: Alpha bitwise operation
Problem Description: https://unstop.com/code/practice/305917
*/

#include <iostream>
#include <vector>
using namespace std;

int alphaBitwiseOperation(vector<int> &A, int N) {
    int result = 0;
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] & (1 << bit)) {
                ++count;
            }
        }
        if (count > N / 2) {
            result |= (1 << bit);
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int result = alphaBitwiseOperation(A, N);
    cout << result << endl;
    return 0;
}
