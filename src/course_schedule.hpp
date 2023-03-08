/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
    You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that 
    you must take course bi first if you want to take course ai.

    Return true if you can finish all courses. Otherwise, return false.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int res = 0;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> queue;

        // Build adjacency list & indegree
        for (auto v : prerequisites)
        {
            int src = v[0];
            int dest = v[1];

            adj[dest].push_back(src);
            indegree[src]++;
        }

        // Push 0 indegree to queue
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                queue.push(i);
            }
        }

        // BFS traversal
        while (!queue.empty())
        {
            int curr = queue.front();
            queue.pop();

            res++;

            for (auto dest : adj[curr])
            {
                // Update course indegree
                indegree[dest]--;

                // Push 0 indegree to queue
                if (indegree[dest] == 0)
                {
                    queue.push(dest);
                }
            }
        }

        // Check whether visited equal to total courses
        return numCourses == res;
    }
};