/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of 
    nodes), write a function to find the number of connected components in an undirected graph.
*/
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
    vector<int> parent;

    int find(int node)
    {
        while (node != parent[node])
        {
            node = parent[node];
        }
        return node;
    }

public:
    int countComponents(int n, vector<pair<int, int>> &edges)
    {
        int res = n;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto e : edges)
        {
            int node1 = find(e.first);
            int node2 = find(e.second);

            if (node1 != node2)
            {
                res--;
                parent[node1] = node2;
            }
        }

        return res;
    }
};