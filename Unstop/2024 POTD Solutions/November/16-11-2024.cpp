/*
Problem of the Day: Maximum Jamun Pick
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-jamun-pick-unstop-solution-b8a73e4f37bf
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxJamuns(vector<int>& bucket) {
    int n = bucket.size();
    if (n == 0) return 0;
    if (n == 1) return bucket[0];
    
    int prev2 = bucket[0];
    int prev1 = max(bucket[0], bucket[1]);
    
    for (int i = 2; i < n; ++i) {
        int curr = max(prev1, bucket[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main() {
    int N;
    cin >> N;
    vector<int> bucket(N);
    for (int i = 0; i < N; ++i) {
        cin >> bucket[i];
    }
    
    cout << maxJamuns(bucket) << endl;
    return 0;
}