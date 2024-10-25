/*
Problem of the Day: 1233. Remove Sub-Folders from the Filesystem
problem Description: https://medium.com/@pradeepsooryavanshee1210/1233-remove-sub-folders-from-the-filesystem-leetcode-solution-2899893db52d
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        
        string lastValid = "";
        for (const string& f : folder) {
            if (lastValid.empty() || f.find(lastValid + "/") != 0) {
                result.push_back(f);
                lastValid = f;
            }
        }
        
        return result;
    }
};
