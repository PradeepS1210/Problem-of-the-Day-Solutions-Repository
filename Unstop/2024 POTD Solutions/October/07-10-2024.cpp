/*
Problem of the Day: Height Comparison
Problem Description: https://medium.com/@pradeepsooryavanshee1210/height-comparison-unstop-solution-c7ae9a554ffe
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void findTallestInGroups(const vector<int>& height, int N, int K) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < K; i++) {
        while (!dq.empty() && height[dq.back()] <= height[i])
            dq.pop_back();
        dq.push_back(i);
    }

    for (int i = K; i < N; i++) {
        result.push_back(height[dq.front()]);

        while (!dq.empty() && dq.front() <= i - K)
            dq.pop_front();

        while (!dq.empty() && height[dq.back()] <= height[i])
            dq.pop_back();

        dq.push_back(i);
    }

    result.push_back(height[dq.front()]);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    findTallestInGroups(height, N, K);

    return 0;
}