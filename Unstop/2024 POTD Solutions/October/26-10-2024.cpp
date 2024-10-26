/*
Problem of the Day: Magical Vowels
Problem Description: https://medium.com/@pradeepsooryavanshee1210/magical-vowels-unstop-solution-8f7107a230e9
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string MagicalVowels(int N, const string &s) {
    vector<char> st;
    int flag = 0;

    for (int i = 0; i < N; i++) {
        if (!isVowel(s[i])) {
            flag = 0;
            st.push_back(s[i]);
        } else {
            if (flag == 0) {
                st.push_back(s[i]);
                flag = 1;
            } else if (flag == 1) {
                if ((i < N - 1 && !isVowel(s[i + 1])) || i == N - 1) {
                    st.push_back(s[i]);
                    st.push_back('$');
                } else {
                    st.push_back(s[i]);
                    flag = 2;
                }
            } else {
                st.push_back(s[i]);
            }
        }
    }

    return string(st.begin(), st.end());
}

int main() {
    int N;
    string s;

    cin >> N >> s;

    cout << MagicalVowels(N, s) << endl;

    return 0;
}
