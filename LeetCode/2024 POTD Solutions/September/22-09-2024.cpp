/*
Problem of the Day: 440. K-th Smallest in Lexicographical Order
*/

class Solution
{
public:
    long countNumbersInRange(long prefix, long n)
    {
        long count = 0;
        long current = prefix;
        long next = prefix + 1;

        while (current <= n)
        {
            count += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k)
    {
        int prefix = 1;
        k--;

        while (k > 0)
        {
            long count = countNumbersInRange(prefix, n);
            if (count <= k)
            {
                k -= count;
                prefix++;
            }
            else
            {
                prefix *= 10;
                k--;
            }
        }

        return prefix;
    }
};
