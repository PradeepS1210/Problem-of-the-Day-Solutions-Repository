/*
Problem of the Day: Shortest path in Undirected Graph
Problem Description: https://medium.com/@pradeepsooryavanshee1210/shortest-path-in-undirected-graph-geeksforgeeks-solution-7c00a553d552
*/

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, INT_MAX);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[node] + 1 < dist[neighbor])
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};