/*
Problem of the Day: 840. Magic Squares In Grid
Problem Description: https://medium.com/@pradeepsooryavanshee1210/840-magic-squares-in-grid-leetcode-solution-cdf83b73fec2
*/

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i <= rows - 3; ++i)
        {
            for (int j = 0; j <= cols - 3; ++j)
            {
                if (isMagicSquare(grid, i, j))
                {
                    ++count;
                }
            }
        }

        return count;
    }

    bool isMagicSquare(const vector<vector<int>> &grid, int startRow, int startCol)
    {
        vector<int> nums(9);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                nums[i * 3 + j] = grid[startRow + i][startCol + j];
            }
        }

        sort(nums.begin(), nums.end());
        if (nums != vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})
        {
            return false;
        }

        int magicSum = 15;

        for (int i = 0; i < 3; ++i)
        {
            if (grid[startRow + i][startCol] + grid[startRow + i][startCol + 1] + grid[startRow + i][startCol + 2] != magicSum)
            {
                return false;
            }
        }

        for (int j = 0; j < 3; ++j)
        {
            if (grid[startRow][startCol + j] + grid[startRow + 1][startCol + j] + grid[startRow + 2][startCol + j] != magicSum)
            {
                return false;
            }
        }

        if (grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2] != magicSum)
        {
            return false;
        }

        if (grid[startRow + 2][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow][startCol + 2] != magicSum)
        {
            return false;
        }

        return true;
    }
};