/*
Problem of the Day: The Misprint
Problem Description: https://unstop.com/code/practice/300733
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string sentence;
        cin >> sentence;
        
        size_t pos = sentence.find("nancy");
        if (pos != string::npos) {
            while (pos != string::npos) {
                sentence.replace(pos, 5, "sanvi");
                pos = sentence.find("nancy", pos + 5);
            }
            cout << sentence << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
