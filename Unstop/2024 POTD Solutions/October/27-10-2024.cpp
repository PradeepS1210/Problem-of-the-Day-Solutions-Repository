/*
Problem of the Day: Convert prime number in string array into alphabet
Problem Description: https://medium.com/@pradeepsooryavanshee1210/convert-prime-number-in-string-array-into-alphabet-unstop-solution-3ca3cca30e0c
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++) {
        int num = stoi(arr[i]);
        if (isPrime(num)) {
            arr[i] = char(num + 'A');
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) cout << " ";
    }
    
    return 0;
}
