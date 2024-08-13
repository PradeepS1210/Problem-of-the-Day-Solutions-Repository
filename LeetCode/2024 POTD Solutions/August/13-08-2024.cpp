/*
Problem of the Day: 40. Combination Sum II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/40-combination-sum-ii-leetcode-solution-e85efa11edba
*/

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int> &candidates, int target, int start,
                   std::vector<int> &combination, std::vector<std::vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back();
        }
    }
};