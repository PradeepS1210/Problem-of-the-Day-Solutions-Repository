/*
Problem of the Day: Frequency Game: Find the Outlier
Problem Description: https://unstop.com/code/practice/521930
*/

#include <bits/stdc++.h>
using namespace std;

int findMinorityElementIndex(vector<int>& nums) {
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    vector<int> frequencies;
    for (auto& entry : freq_map) {
        frequencies.push_back(entry.second);
    }

    sort(frequencies.begin(), frequencies.end());
    int median_freq = frequencies[frequencies.size() / 2];

    int chosen_element = INT_MAX;
    int first_occurrence = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (freq_map[nums[i]] == median_freq) {
            if (nums[i] < chosen_element || (nums[i] == chosen_element && first_occurrence == -1)) {
                chosen_element = nums[i];
                first_occurrence = i + 1; // 1-based indexing
            }
        }
    }

    return first_occurrence;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cout << findMinorityElementIndex(nums) << endl;

    return 0;
}
