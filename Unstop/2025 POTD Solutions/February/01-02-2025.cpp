/*
Problem of the Day: Can Mira Restore the Magical Garden's Balance?
Problem Description: https://unstop.com/code/practice/491897
*/

#include <iostream>
#include <string>

using namespace std;

bool can_restore_harmony(int N, int h, string &S) {
    int b_count = 0, w_count = 0, x_count = 0;

    for (int i = 0; i < h; ++i) {
        if (S[i] == 'b') {
            b_count++;
        } else if (S[i] == 'w') {
            w_count++;
        } else {  // 'x'
            x_count++;
        }
    }

    auto is_valid = [h](int b, int w, int x) {
        int target = h / 2;
        if (b > target || w > target) {
            return false;
        }
        return true;
    };

    if (!is_valid(b_count, w_count, x_count)) {
        return false;
    }

    for (int i = h; i < N; ++i) {
        if (S[i] == 'b') {
            b_count++;
        } else if (S[i] == 'w') {
            w_count++;
        } else {
            x_count++;
        }

        if (S[i - h] == 'b') {
            b_count--;
        } else if (S[i - h] == 'w') {
            w_count--;
        } else {
            x_count--;
        }

        if (!is_valid(b_count, w_count, x_count)) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, h;
    string S;

    cin >> N >> h;
    cin >> S;

    if (can_restore_harmony(N, h, S)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
