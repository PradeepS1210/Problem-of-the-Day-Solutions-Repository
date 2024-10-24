/*
problem of the Day: Factorial Buzz
Problem Description: https://medium.com/@pradeepsooryavanshee1210/factorial-buzz-unstop-solution-a1b77564a9a3
*/

#include <iostream>
#include <vector>
using namespace std;

int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        int maxTrailingZeros = 0;
        
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            int trailingZeros = countTrailingZeros(arr[i]);
            maxTrailingZeros = max(maxTrailingZeros, trailingZeros);
        }
        
        cout << maxTrailingZeros << '\n';
    }
    
    return 0;
}
