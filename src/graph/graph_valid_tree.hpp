#include <vector>

using namespace std;

/*
    Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of
    nodes), write a function to check whether these edges make up a valid tree.

    Note: you can assume that no duplicate edges will appear in edges. Since all edges are
    undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/
class Solution
{
    int find(vector<int> &roots, int i)
    {
        while (roots[i] != -1)
        {
            i = roots[i];
        }
        return i;
    }

public:
    bool validTree(int n, vector<pair<int, int>> &edges)
    {
        // A valid tree has to satisfy the criterions:
        //  1) all nodes are connected
        //  2) no cycle

        // Initialize all root to -1
        vector<int> roots(n, -1);

        for (auto a : edges)
        {
            int x = find(roots, a.first);
            int y = find(roots, a.second);

            // If root of nodes are the same, there is a cycle
            if (x == y)
            {
                return false;
            }

            roots[x] = y;
        }

        // Check whether all nodes are connected (no duplicated edges)
        return edges.size() == n - 1;
    }
};