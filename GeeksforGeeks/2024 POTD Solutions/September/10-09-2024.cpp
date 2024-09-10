/*
Asked in Flipkart, Accolite, Microsoft, FactSet
Problem of the Day: Circle of strings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/circle-of-strings-geeksforgeeks-solution-94e9bf509302
*/

class Solution
{
public:
    int isCircle(std::vector<std::string> &arr)
    {
        if (arr.empty())
            return 0;

        std::unordered_map<char, int> inDegree, outDegree;
        std::unordered_map<char, std::unordered_set<char>> adjList;

        for (const std::string &str : arr)
        {
            char first = str.front();
            char last = str.back();
            outDegree[first]++;
            inDegree[last]++;
            adjList[first].insert(last);
        }

        for (const auto &entry : outDegree)
        {
            if (entry.second != inDegree[entry.first])
            {
                return 0;
            }
        }

        std::unordered_set<char> visited;
        char start = arr[0].front();
        dfs(start, adjList, visited);

        for (const auto &entry : outDegree)
        {
            if (entry.second > 0 && visited.find(entry.first) == visited.end())
            {
                return 0;
            }
        }

        return 1;
    }

private:
    void dfs(char node, std::unordered_map<char, std::unordered_set<char>> &adjList, std::unordered_set<char> &visited)
    {
        visited.insert(node);
        for (char neighbor : adjList[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, adjList, visited);
            }
        }
    }
};