/*
Problem of the Day: Pair of Subarrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/pair-of-subarrays-unstop-solution-9962976b5882
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countEqualSumPairs(vector<int>& A) {
    int N = A.size();
    vector<long long> prefix(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }

    unordered_map<long long, vector<int>> sumMap;
    int count = 0;

    for (int R = 1; R <= N; R++) {
        for (int L = 1; L <= R; L++) {
            long long sum = prefix[R] - prefix[L - 1];
            
            for (int prevEnd : sumMap[sum]) {
                if (prevEnd < L) {
                    count++;
                }
            }
            sumMap[sum].push_back(R);
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << countEqualSumPairs(A) << endl;
    return 0;
}
