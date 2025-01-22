/*
Problem of the Day: Counting Magical Plant IDs
Problem Description: https://unstop.com/code/practice/518760
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool hasExactlyFiveDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                count += 1;
            } else {
                count += 2;
            }
        }
    }
    return count == 5;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> magicalIDs;
    for (long long i = 1; i * i <= N; ++i) {
        long long square = i * i;
        if (hasExactlyFiveDivisors(square)) {
            magicalIDs.push_back(square);
        }
    }

    cout << magicalIDs.size() << endl;
    for (long long id : magicalIDs) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
