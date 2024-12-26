/*
Problem of the Day: Harshavardhan's Enchanted Crystal Combinations
Problem Description: https://unstop.com/code/practice/477062
*/

#include <iostream>
using namespace std;

long long countCombinations(int N) {
    long long count = 0;
    for (int a = 1; a * a * a <= N; ++a) {
        for (int b = a; a * b * b <= N; ++b) {
            int max_c = N / (a * b);
            count += (max_c - b + 1);
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    cout << countCombinations(N) << endl;

    return 0;
}
