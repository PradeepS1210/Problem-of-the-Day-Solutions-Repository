/*
Problem of the Day: Trailing Zeros in Numbers
Problem Description: https://unstop.com/code/practice/519585
*/

#include <iostream>
#include <vector>
using namespace std;

int trailingZeros(int num) {
    int count = 0;
    for (int i = 5; num / i >= 1; i *= 5) {
        count += num / i;
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    int totalTrailingZeros = 0;
    
    for (int i = 0; i < N; ++i) {
        if (arr[i] <= M) {
            totalTrailingZeros += trailingZeros(arr[i]);
        }
    }
    
    cout << totalTrailingZeros << endl;
    
    return 0;
}
