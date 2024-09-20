/*
Problem of the Day: Facing the sun
Problem Description: https://medium.com/@pradeepsooryavanshee1210/amazon-interview-question-facing-the-sun-geeksforgeeks-solution-b2d38f15ebe1
*/

class Solution
{
public:
    int countBuildings(vector<int> &height)
    {
        int count = 0;
        int maxHeight = 0;

        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] > maxHeight)
            {
                count++;
                maxHeight = height[i];
            }
        }
        return count;
    }
};