/*
Problem of the Day: Single Value Tree
Problem Description: https://unstop.com/code/practice/250895
*/

#include <bits/stdc++.h>
using namespace std;

bool isSingleValuedTree(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return false;

    int rootValue = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] != -1 && arr[i] != rootValue) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> arr;
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    if (isSingleValuedTree(arr)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}
