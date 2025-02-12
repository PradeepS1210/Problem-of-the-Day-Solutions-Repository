/*
Problem of the Day: Meal Arrangement for Guests
Problem Description: https://unstop.com/code/practice/528235
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string D;
    cin >> D;
    unordered_map<char, int> veg_count, nonveg_count;

    for (char dish : D) {
        if (dish == 'a' || dish == 'e' || dish == 'i' || dish == 'o' || dish == 'u') {
            veg_count[dish]++;
        } else {
            nonveg_count[dish]++;
        }
    }

    vector<pair<char, int>> veg_groups(veg_count.begin(), veg_count.end());
    vector<pair<char, int>> nonveg_groups(nonveg_count.begin(), nonveg_count.end());

    sort(veg_groups.begin(), veg_groups.end(), [](pair<char, int> &a, pair<char, int> &b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    sort(nonveg_groups.begin(), nonveg_groups.end(), [](pair<char, int> &a, pair<char, int> &b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    string result;

    for (auto &group : veg_groups) {
        result += group.first + to_string(group.second);
    }

    for (auto &group : nonveg_groups) {
        result += group.first + to_string(group.second);
    }

    if (result.empty()) {
        cout << "NULL" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
