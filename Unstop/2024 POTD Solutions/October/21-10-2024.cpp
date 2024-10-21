/*
Problem of the Day: Rearrange Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/rearrange-linked-list-unstop-solution-c0dd1f25a4cf
*/

#include <iostream>
#include <vector>
using namespace std;

void rearrangeList(vector<int>& list) {
    int n = list.size();
    
    vector<int> group1, group2, group3;
    
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            group1.push_back(list[i]);
        } else if (i % 3 == 1) {
            group2.push_back(list[i]);
        } else {
            group3.push_back(list[i]);
        }
    }
    
    int idx = 0;
    
    for (int i = 0; i < group1.size(); ++i) {
        list[idx++] = group1[i];
    }
    
    for (int i = 0; i < group2.size(); ++i) {
        list[idx++] = group2[i];
    }
    
    for (int i = 0; i < group3.size(); ++i) {
        list[idx++] = group3[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }
    
    rearrangeList(list);
    
    for (int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
    
    return 0;
}
