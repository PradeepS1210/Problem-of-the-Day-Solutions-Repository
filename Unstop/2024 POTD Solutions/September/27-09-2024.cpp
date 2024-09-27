/*
Asked in Google, nvidia, Goldman Sachs
Problem of the Day: Minimum operations to make zero
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-operations-to-make-zero-unstop-solution-1c18d8caf590
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minimumOneBitOperations(int n, int res)
{
    if (n == 0)
    {
        return res;
    }

    int b = 1;
    while ((b << 1) <= n)
    {
        b = b << 1;
    }

    return minimumOneBitOperations((b >> 1) ^ b ^ n, res + b);
}

vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> sieve(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p)
    {
        if (sieve[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                sieve[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p)
    {
        if (sieve[p])
        {
            primes.push_back(p);
        }
    }

    return primes;
}

int main()
{
    int N;
    cin >> N;

    int ans = minimumOneBitOperations(N, 0);
    vector<int> primes = sieveOfEratosthenes(ans);

    cout << primes.size() << endl;

    return 0;
}