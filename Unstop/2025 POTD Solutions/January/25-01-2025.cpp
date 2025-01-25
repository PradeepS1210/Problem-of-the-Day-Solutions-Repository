/*
Problem of the Day: Reverse Mirror Encoding
Problem Description: https://unstop.com/code/practice/508821
*/

#include <iostream>
#include <string>

using namespace std;

string decodeMessage(const string &encoded) {
    string decoded = "";
    int i = 0;

    while (i < encoded.length()) {
        char ch = encoded[i];

        if (ch >= 'a' && ch <= 'n') {
            decoded += 'n' - (ch - 'a');
            i++;
        } else if (ch >= 'o' && ch <= 'z' && i + 1 < encoded.length() && encoded[i + 1] == '#') {
            decoded += 'o' + ('z' - ch);
            i += 2;
        } else {
            i++;
        }
    }

    return decoded;
}

int main() {
    string encoded;
    cin >> encoded;
    cout << decodeMessage(encoded) << endl;
    return 0;
}
