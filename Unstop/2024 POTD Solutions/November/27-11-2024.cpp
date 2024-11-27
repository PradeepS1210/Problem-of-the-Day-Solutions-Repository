/*
Problem of the Day: Frequency Plot  
Problem Description: https://medium.com/@pradeepsooryavanshee1210/frequency-plot-unstop-solution-8ef2993ccf86
*/

#include <bits/stdc++.h>
using namespace std;

int largestMinFreqElement(int N, vector<int>& arr) {
    unordered_map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    int minFreq = INT_MAX;
    int result = INT_MIN;

    for (auto& pair : freqMap) {
        int element = pair.first;
        int frequency = pair.second;

        if (frequency < minFreq) {
            minFreq = frequency;
            result = element;
        } else if (frequency == minFreq) {
            result = max(result, element);
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << largestMinFreqElement(N, arr) << endl;

    return 0;
}