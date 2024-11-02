/*
Problem of the Day: NM by XY
Problem Description: https://medium.com/@pradeepsooryavanshee1210/nm-by-xy-unstop-solution-b8566811a9cd
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> NMbyXY(int x, int y) {
    vector<int> vec;
    if ((x - y) % 2 != 0 || x < y) {
        vec.push_back(-1);
    } else {
        vec.push_back((x - y) / 2);
        vec.push_back(x - (x - y) / 2);
    }
    return vec;
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> vec = NMbyXY(x, y);
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}