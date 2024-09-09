/*
Problem of the Day: 2326. Spiral Matrix IV
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2326-spiral-matrix-iv-leetcode-solution-c4d0a66c433d
*/

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode *curr = head;

        while (curr != nullptr && top <= bottom && left <= right)
        {
            for (int i = left; i <= right && curr != nullptr; ++i)
            {
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for (int i = top; i <= bottom && curr != nullptr; ++i)
            {
                matrix[i][right] = curr->val;
                curr = curr->next;
            }
            right--;

            for (int i = right; i >= left && curr != nullptr; --i)
            {
                matrix[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;

            for (int i = bottom; i >= top && curr != nullptr; --i)
            {
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }

        return matrix;
    }
};