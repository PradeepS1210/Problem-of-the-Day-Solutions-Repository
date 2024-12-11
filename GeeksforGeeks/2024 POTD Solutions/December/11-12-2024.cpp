/*
Problem of the Day: Merge Without Extra Space
Problem Description: https://medium.com/@pradeepsooryavanshee1210/merge-without-extra-space-geeksforgeeks-solution-2a1671a98bbb
*/

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = ceil((double)(n + m) / 2);

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < n) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
                i++;
                j++;
            }

            j = j - n;
            while (i < n && j < m) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                }
                i++;
                j++;
            }

            i = 0;
            while (j < m) {
                if (b[i] > b[j]) {
                    swap(b[i], b[j]);
                }
                i++;
                j++;
            }

            if (gap == 1) {
                gap = 0;
            } else {
                gap = ceil((double)gap / 2);
            }
        }
    }
};