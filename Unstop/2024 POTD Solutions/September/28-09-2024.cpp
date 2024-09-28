/*
Asked in Avizva, Accenture, Wipro
Problem of the Day: Password Check
Problem Description: https://medium.com/@pradeepsooryavanshee1210/password-check-unstop-solution-84394e691997
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int password[N];
    for (int i = 0; i < N; i++) {
        cin >> password[i];
    }
    
    unordered_map<int, int> freqMap;
    for (int i = 0; i < N; i++) {
        freqMap[password[i]]++;
    }
    
    unordered_set<int> freqSet;
    for (auto it : freqMap) {
        freqSet.insert(it.second);
    }
    
    if (freqSet.size() == freqMap.size()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}