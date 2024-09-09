/*
Asked in Paytm, Flipkart, Morgan Stanley, Amazon, Microsoft, OYO Rooms, Samsung, Snapdeal, Hike, MakeMyTrip, Ola Cabs, Walmart, MAQ Software, Adobe, Yatra.com, SAP Labs, Qualcomm
Problem of the Day: Sort 0s, 1s and 2s
Problem Description: https://medium.com/@pradeepsooryavanshee1210/amazon-16-companies-interview-question-sort-0s-1s-and-2s-geeksforgeeks-solution-a15868987fac
*/

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int low = 0, mid = 0;
        int high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};