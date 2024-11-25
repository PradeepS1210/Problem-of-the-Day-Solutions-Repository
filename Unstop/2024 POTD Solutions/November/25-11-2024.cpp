/*
Problem of the Day: Linked List Multiplication
Problem Description: https://medium.com/@pradeepsooryavanshee1210/linked-list-multiplication-unstop-solution-d304f17dc502
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    long long int num1 = stoll(a);
    long long int num2 = stoll(b);
    
    cout << num1 * num2 << endl;

    return 0;
}