/*
Problem of the Day: Crystal Power
Problem Description: https://medium.com/@pradeepsooryavanshee1210/crystal-power-unstop-solution-38b5d4da1c09
*/

#include <stdio.h>
#include <string.h>

long long solve(long long* nums, long long n, long long target) {
    long long count[target + 1];
    memset(count, 0, sizeof(count));
    count[0] = 1;

    for (long long i = 1; i <= target; i++) {
        for (long long j = 0; j < n; j++) {
            if (i >= nums[j]) {
                count[i] += count[i - nums[j]];
            }
        }
    }

    return count[target];r
}

int main() {
    long long n, target;
    scanf("%lld %lld", &n, &target);

    long long nums[n];
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }

    printf("%lld\n", solve(nums, n, target));
    return 0;
}