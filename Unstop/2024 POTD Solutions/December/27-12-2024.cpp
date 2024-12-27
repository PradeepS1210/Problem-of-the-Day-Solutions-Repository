/*
Problem of the Day: Volcanic Mineral Growth: Tracking Size Changes Over Time
Problem Description: https://unstop.com/code/practice/480984
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateMineralSize(vector<int>& sizes, int days) {
    vector<int> result;
    for (int size : sizes) {
        int currentSize = size;
        for (int day = 1; day <= days; ++day) {
            if (day % 3 == 0) {
                currentSize /= 2;
            } else {
                currentSize *= 2;
            }
        }
        result.push_back(currentSize);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> sizes(N);
    for (int i = 0; i < N; ++i) {
        cin >> sizes[i];
    }
    int D;
    cin >> D;

    vector<int> result = calculateMineralSize(sizes, D);

    for (int size : result) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
