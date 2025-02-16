/*
Problem of the Day: Dynamic Region Sum Calculation in Matrix
Problem Description: https://unstop.com/code/practice/514987
*/

#include <bits/stdc++.h>
using namespace std;

void addElement(int i, int j, unordered_set<int>& countedElements, int& totalSum, const vector<vector<int>>& matrix) {
    int key = i * matrix.size() + j;
    if (countedElements.insert(key).second) {
        totalSum += matrix[i][j];
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    unordered_set<int> countedElements;
    int totalSum = 0;

    for (int i = 0; i < N; ++i) {
        addElement(i, i, countedElements, totalSum, matrix);
        if (i > 0) addElement(i, i - 1, countedElements, totalSum, matrix);
        if (i < N - 1) addElement(i, i + 1, countedElements, totalSum, matrix);
    }

    for (int i = 0; i < N; ++i) {
        addElement(0, i, countedElements, totalSum, matrix);
        addElement(N - 1, i, countedElements, totalSum, matrix);
        if (i > 0 && i < N - 1) {
            addElement(i, 0, countedElements, totalSum, matrix);
            addElement(i, N - 1, countedElements, totalSum, matrix);
        }
    }

    int start = (N - K) / 2;
    int end = start + K;
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end; ++j) {
            addElement(i, j, countedElements, totalSum, matrix);
        }
    }

    cout << totalSum << endl;

    return 0;
}
