/*
Problem of the Day: Word Search
Problem Description: https://www.geeksforgeeks.org/problems/word-search/1
*/


class Solution {
private:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) return false; // Boundaries or mismatch check
        
        char temp = mat[i][j];
        mat[i][j] = '*';
        
        bool found = dfs(mat, word, i-1, j, index+1) || dfs(mat, word, i+1, j, index+1) || 
                     dfs(mat, word, i, j-1, index+1) || dfs(mat, word, i, j+1, index+1);
        
        mat[i][j] = temp;
        return found;
    }
    
public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
