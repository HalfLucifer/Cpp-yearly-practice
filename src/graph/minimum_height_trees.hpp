#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
        {
            return {};
        }
        else if (n == 1)
        {
            return {0};
        }

        // To find the middle node(s) of tree, proceed with BFS traversal from leaf nodes
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);

        // Build ajacency list and degree
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dst = edges[i][1];

            adj[src].push_back(dst);
            adj[dst].push_back(src);

            degree[src]++;
            degree[dst]++;
        }

        // Push leaf nodes to queue
        queue<int> queue;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
            {
                queue.push(i);
            }
        }

        vector<int> res;

        // BFS traversal
        while (!queue.empty())
        {
            // Clear current collection if there is node to handle
            res.clear();
            // Traverse by level
            int size = queue.size();

            for (int i = 0; i < size; i++)
            {
                int curr = queue.front();
                queue.pop();

                // Push current node to collection, until there are 1 or 2 nodes left
                res.push_back(curr);

                for (auto &next : adj[curr])
                {
                    degree[next]--;

                    // Push leaf nodes to queue
                    if (degree[next] == 1)
                    {
                        queue.push(next);
                    }
                }
            }
        }

        return res;
    }
};