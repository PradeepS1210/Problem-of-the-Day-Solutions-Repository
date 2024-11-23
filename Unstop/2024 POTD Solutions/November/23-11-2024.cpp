/*
Problem of the Day: Alice’s K Negations
Problem Description: https://medium.com/@pradeepsooryavanshee1210/alices-k-negations-unstop-solution-4bd7d36421b6
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N && K > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            K--;
        }
    }

    if (K % 2 == 1) {
        sort(arr.begin(), arr.end());
        arr[0] = -arr[0];
    }

    long long sum = accumulate(arr.begin(), arr.end(), 0LL);

    cout << sum << endl;
    return 0;
}