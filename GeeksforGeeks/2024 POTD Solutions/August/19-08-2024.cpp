/*
Asked in VMWare, Accolite, Amazon, Microsoft, Snapdeal, Hike, Adobe, Google, ABCO, Cisco
Problem of the Day: Kth Smallest
problem Description: https://medium.com/@pradeepsooryavanshee1210/amazon-9-more-companies-interview-question-solution-77a97e3065d4
*/

class Solution
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    int quickSelect(vector<int> &arr, int low, int high, int k)
    {
        if (low <= high)
        {
            int pivotIndex = partition(arr, low, high);

            if (pivotIndex == k - 1)
                return arr[pivotIndex];

            if (pivotIndex > k - 1)
                return quickSelect(arr, low, pivotIndex - 1, k);

            return quickSelect(arr, pivotIndex + 1, high, k);
        }
        return -1;
    }

    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        return quickSelect(arr, 0, n - 1, k);
    }
};