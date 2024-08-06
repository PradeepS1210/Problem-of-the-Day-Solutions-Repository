/*
Problem of the Day: Convert it
Problem Description: https://medium.com/@pradeepsooryavanshee1210/convert-it-unstop-solution-problem-of-the-day-e508982d028e
*/

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }

    int max_val = arr[0];
    for (int i = 0; i < N; ++i)
    {
        max_val = std::max(max_val, arr[i]);
        arr[i] += max_val;
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}