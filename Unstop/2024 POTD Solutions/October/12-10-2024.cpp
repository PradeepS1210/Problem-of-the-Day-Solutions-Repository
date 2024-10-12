/*
Problem of the Day: Genie’s Condition
Problem Description: https://medium.com/@pradeepsooryavanshee1210/genies-condition-unstop-solution-c5ed0c78ad32
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxGCD(vector<int>& arr, int N) {
    int maxValue = *max_element(arr.begin(), arr.end());
    
    vector<int> freq(maxValue + 1, 0);
    
    for (int num : arr) {
        freq[num]++;
    }
    
    for (int g = maxValue; g >= 1; g--) {
        int count = 0;
        
        for (int multiple = g; multiple <= maxValue; multiple += g) {
            count += freq[multiple];
        }
        
        if (count >= 2) {
            return g;
        }
    }
    
    return 1;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << maxGCD(arr, N) << endl;
    
    return 0;
}