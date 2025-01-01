/*
Asked in Morgan Stanley, Amazon, Microsoft, Snapdeal, D-E-Shaw, Goldman Sachs
Problem of the Day: Print Anagrams Together
Problem Description: https://www.geeksforgeeks.org/problems/print-anagrams-together/1
*/

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& word : arr) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            anagramGroups[sortedWord].push_back(word);
        }
        
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};