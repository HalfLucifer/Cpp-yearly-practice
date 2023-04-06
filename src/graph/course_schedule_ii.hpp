/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you
    must take course bi first if you want to take course ai.

    Return the ordering of courses you should take to finish all courses. If there are many
    valid answers, return any of them. If it is impossible to finish all courses, return an
    empty array.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for (auto course : prerequisites)
        {
            int src = course[1];
            int dest = course[0];

            adj[src].push_back(dest);
            indegree[dest]++;
        }

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (auto e : adj[curr])
            {
                indegree[e]--;

                if (indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }

        return res;
    }
};