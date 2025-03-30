/*
Problem of the Day: Gas Station
Problem Description: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
*/

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;
       
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            if (currentGas < 0) {
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};
