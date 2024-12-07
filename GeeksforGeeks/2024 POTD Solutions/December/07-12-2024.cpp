/*
Problem of the Day: Count Inversions
Problem Description: https://medium.com/@pradeepsooryavanshee1210/count-inversions-geeksforgeeks-solution-e143d646515e
*/

class Solution {
  public:
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
        
        int i = 0, j = 0, k = left, invCount = 0;
        int n1 = leftArr.size(), n2 = rightArr.size();
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                invCount += (n1 - i);
            }
        }
        
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
        
        return invCount;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            invCount += mergeSortAndCount(arr, left, mid);
            invCount += mergeSortAndCount(arr, mid + 1, right);
            
            invCount += mergeAndCount(arr, left, mid, right);
        }
        return invCount;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};