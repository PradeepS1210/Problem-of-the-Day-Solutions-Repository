#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> Arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> Arr[i];
    }
    
    long long totalSum = 0;
    for (int i = 0; i < N; ++i) {
        totalSum += Arr[i];
    }
    
    long long maxProduct = 0;
    long long firstPartSum = 0;
    for (int i = 0; i < N - 1; ++i) {
        firstPartSum += Arr[i];
        long long secondPartSum = totalSum - firstPartSum;
        maxProduct = max(maxProduct, firstPartSum * secondPartSum);
    }
    
    cout << maxProduct << endl;
    
    return 0;
}
