/*
Problem of the Day: Sort 0s, 1s and 2s
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sort-0s-1s-and-2s-geeksforgeeks-solution-84bd73442c08
*/

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};