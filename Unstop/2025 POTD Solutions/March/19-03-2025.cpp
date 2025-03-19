/*
Problem of the Day: Add two binary string integers after shifting left and right
Problem Description: https://unstop.com/code/practice/299148
*/

#include <bits/stdc++.h>
using namespace std;

string shiftAndAddBinaryStrings(int N, const string &A, const string &B) {
    unsigned long long a = bitset<64>(A).to_ullong();
    unsigned long long b = bitset<64>(B).to_ullong();

    unsigned long long shiftedA = a << N;
    unsigned long long shiftedB = b >> N;

    unsigned long long result = shiftedA + shiftedB;
  
    return bitset<128>(result).to_string().substr(bitset<128>(result).to_string().find('1'));
}

int main() {
    int N;
    string A, B;
  
    cin >> N;
    cin >> A;
    cin >> B;

    cout << shiftAndAddBinaryStrings(N, A, B) << endl;

    return 0;
}
