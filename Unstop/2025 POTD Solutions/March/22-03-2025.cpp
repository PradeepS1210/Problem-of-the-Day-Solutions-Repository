/*
Problem of the Day: Maximum Consecutive Tasks
Problem Description: https://unstop.com/code/practice/548699
*/

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveTasks(vector<int>& tasks, int T) {
    int n = tasks.size();
    int left = 0, sum = 0, maxTasks = 0;

    for (int right = 0; right < n; ++right) {
        sum += tasks[right];
        
        while (sum > T) {
            sum -= tasks[left];
            left++;
        }
        
        maxTasks = max(maxTasks, right - left + 1);
    }
    
    return maxTasks;
}

int main() {
    int N, T;
    cin >> N;

    vector<int> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i];
    }
    cin >> T;

    cout << maxConsecutiveTasks(tasks, T) << endl;

    return 0;
}
