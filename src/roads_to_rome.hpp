/*
    Find out whether all roads lead to Rome (one and only one destination).
    If Rome exists, return its node index, otherwise returns -1.

    Given that no cycle is existed.
 */
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int allRoadsLeadToRome(vector<int> &A, vector<int> &B)
    {
        int count = A.size() + 1;
        int unvisited = count;

        vector<vector<int>> adj(count);
        vector<int> indegree(count, 0);
        queue<int> queue;

        // Build adjacency & indegree list
        for (int i = 0; i < A.size(); i++)
        {
            int src = A[i];
            int dest = B[i];

            adj[src].push_back(dest);
            indegree[dest]++;
        }

        // Push 0 indegree nodes to queue
        for (int i = 0; i < count; i++)
        {
            if (indegree[i] == 0)
            {
                queue.push(i);
            }
        }

        // BFS: going from edges to Rome
        while (!queue.empty())
        {
            int count = queue.size();

            for (int i = 0; i < count; i++)
            {
                int node = queue.front();
                queue.pop();
                unvisited--;

                for (int j = 0; j < adj[node].size(); j++)
                {
                    int dest = adj[node][j];
                    indegree[dest]--;

                    // Push to queue when indegree goes to 0
                    if (indegree[dest] == 0)
                    {
                        queue.push(dest);
                    }
                }
            }

            // Exit condition: when unvisted nodes equals to the length of queue,
            // it reaches the end of traversal
            if (unvisited == queue.size())
            {
                if (queue.size() == 1)
                {
                    return queue.front();
                }
                else
                {
                    return -1;
                }
            }
        }

        return -1;
    }
};

/*
    // Test cases

    vector<int> A1 = {1, 2, 3, 4};
    vector<int> B1 = {0, 0, 0, 0};
    int res1 = s.allRoadsLeadToRome(A1, B1); // 0

    vector<int> A2 = {0, 1, 2, 4, 5};
    vector<int> B2 = {2, 2, 3, 3, 3};
    int res2 = s.allRoadsLeadToRome(A2, B2); // 3

    vector<int> A3 = {0, 1, 2, 3};
    vector<int> B3 = {1, 2, 3, 4};
    int res3 = s.allRoadsLeadToRome(A3, B3); // 4
*/