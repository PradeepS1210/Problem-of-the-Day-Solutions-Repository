/*
Problem of the Day: First Wrong Decision
Problem Description: https://unstop.com/code/practice/250927
*/

#include <iostream>
#include <string>
using namespace std;

int findFirstWrongDecision(const string &decisions) {
    for (size_t i = 0; i < decisions.length(); ++i) {
        if (decisions[i] == 'W') {
            return i;
        }
    }
    return -1;
}

int main() {
    string decisions;
    cin >> decisions;
    
    int result = findFirstWrongDecision(decisions);
    cout << result << endl;

    return 0;
}
