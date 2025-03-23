/*
Problem of the Day: Maximum Length of Consecutive Work Segments
Problem Description: https://unstop.com/code/practice/550498
*/

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveDays(vector<int>& workHours, int M) {
    int n = workHours.size();
    deque<int> maxDeque, minDeque;
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; ++right) {
        while (!maxDeque.empty() && workHours[maxDeque.back()] <= workHours[right])
            maxDeque.pop_back();
        maxDeque.push_back(right);

        while (!minDeque.empty() && workHours[minDeque.back()] >= workHours[right])
            minDeque.pop_back();
        minDeque.push_back(right);

        while (workHours[maxDeque.front()] - workHours[minDeque.front()] > M) {
            if (maxDeque.front() == left) maxDeque.pop_front();
            if (minDeque.front() == left) minDeque.pop_front();
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> workHours(N);
    for (int i = 0; i < N; ++i)
        cin >> workHours[i];
    cin >> M;

    cout << maxConsecutiveDays(workHours, M) << endl;
    return 0;
}
