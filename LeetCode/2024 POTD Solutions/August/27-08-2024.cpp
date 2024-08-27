/*
Problem of the Day: 1514. Path with Maximum Probability
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1514-path-with-maximum-probability-leetcode-solution-183b46d6c55a
*/

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while (!pq.empty())
        {
            auto [curProb, node] = pq.top();
            pq.pop();

            if (node == end_node)
            {
                return curProb;
            }

            for (auto &[neighbor, edgeProb] : graph[node])
            {
                double newProb = curProb * edgeProb;
                if (newProb > maxProb[neighbor])
                {
                    maxProb[neighbor] = newProb;
                    pq.emplace(newProb, neighbor);
                }
            }
        }

        return 0.0;
    }
};