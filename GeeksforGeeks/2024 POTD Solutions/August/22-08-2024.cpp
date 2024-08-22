/*
Asked in Flipkart, Amazon, Microsoft, OYO Rooms, Walmart, Google
Problem of the Day: Alien Dictionary
Problem Description: https://medium.com/@pradeepsooryavanshee1210/google-5-more-companies-interview-question-alien-dictionary-geeksforgeeks-solution-1f279bda6465
*/

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            for (int j = 0; j < min(word1.length(), word2.length()); j++)
            {
                if (word1[j] != word2[j])
                {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> inDegree(K, 0);

        for (int u = 0; u < K; u++)
        {
            for (int v : adj[u])
            {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        string result;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');

            for (int v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if (result.length() != K)
            return "";

        return result;
    }
};