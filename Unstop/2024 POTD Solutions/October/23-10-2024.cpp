/*
Problem of the Day: Counting Problem
Problem Description: https://medium.com/@pradeepsooryavanshee1210/counting-problem-unstop-solution-268470cb1cf3
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int countUniqueNumbers(vector<int>& arr) {
    unordered_map<int, int> freq;
    priority_queue<int> maxHeap;

    for (int num : arr) {
        freq[num]++;
        maxHeap.push(num);
    }

    int uniqueCount = 0;

    while (!maxHeap.empty()) {
        int maxNum = maxHeap.top();
        maxHeap.pop();

        if (freq[maxNum] == 0) continue;

        if (freq[maxNum] == 1) {
            uniqueCount++;
            int halfNum = maxNum / 2;
            if (halfNum > 0) {
                maxHeap.push(halfNum);
                freq[halfNum]++;
            }
        }

        freq[maxNum] = 0;
    }

    return uniqueCount;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = countUniqueNumbers(arr);
    cout << result << endl;

    return 0;
}
