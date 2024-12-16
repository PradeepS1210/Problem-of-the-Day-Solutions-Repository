/*
Problem of the Day: K-th element of two Arrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/k-th-element-of-two-arrays-geeksforgeeks-solution-2371e9c1710e
*/

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        if (a.size() > b.size()) {
            return kthElement(b, a, k);
        }

        int n1 = a.size();
        int n2 = b.size();
        int low = max(0, k - n2), high = min(k, n1);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : b[cut2];

            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return -1;
    }
};