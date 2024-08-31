/*
Problem of the Day: 1514. Path with Maximum Probability
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1514-path-with-maximum-probability-leetcode-solution-8eb22a5373b1
*/

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i)
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
            auto [currProb, currNode] = pq.top();
            pq.pop();

            if (currNode == end_node)
            {
                return currProb;
            }

            for (const auto &[nextNode, edgeProb] : graph[currNode])
            {
                double newProb = currProb * edgeProb;
                if (newProb > maxProb[nextNode])
                {
                    maxProb[nextNode] = newProb;
                    pq.emplace(newProb, nextNode);
                }
            }
        }

        return 0.0;
    }
};