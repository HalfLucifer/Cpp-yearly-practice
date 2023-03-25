/*
    You are given an m x n grid where each cell can have one of three values:

    - 0 representing an empty cell,
    - 1 representing a fresh orange, or
    - 2 representing a rotten orange.

    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is
    impossible, return -1.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int res = 0;
        int freshOranges = 0;

        vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> queue;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
                else if (grid[i][j] == 2)
                {
                    queue.push({i, j});
                }
            }
        }

        while (!queue.empty())
        {
            bool hasRotten = false;
            int size = queue.size();

            for (int i = 0; i < size; i++)
            {
                auto [row, col] = queue.front();
                queue.pop();

                for (auto d : DIR)
                {
                    int r = row + d.first;
                    int c = col + d.second;

                    if (r >= 0 && r <= grid.size() - 1 && c >= 0 && c <= grid[0].size() - 1 && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        freshOranges--;
                        hasRotten = true;
                        queue.push({r, c});
                    }
                }
            }

            if (hasRotten)
            {
                res++;
            }
        }

        return freshOranges > 0 ? -1 : res;
    }
};