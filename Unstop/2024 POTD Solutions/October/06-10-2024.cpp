/*
Problem of the Day: Maximum Profit
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-profit-unstop-solution-544dcde3bee5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < N; i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;

    return 0;
}