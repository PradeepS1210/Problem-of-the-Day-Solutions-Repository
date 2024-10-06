/*
Problem of the Day: 2491. Divide Players Into Teams of Equal Skill
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2491-divide-players-into-teams-of-equal-skill-leetcode-solution-bd4b53912f0c
*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        
        long long totalChemistry = 0;
        int n = skill.size();
        int targetSum = skill[0] + skill[n - 1];
        
        for (int i = 0; i < n / 2; ++i) {
            int pairedSum = skill[i] + skill[n - 1 - i];
            
            if (pairedSum != targetSum) {
                return -1;
            }
            
            totalChemistry += skill[i] * skill[n - 1 - i];
        }
        
        return totalChemistry;
    }
};