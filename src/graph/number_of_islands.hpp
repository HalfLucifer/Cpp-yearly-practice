/*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
    return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
    vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <vector>

using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        if (row < 0 || row > grid.size() - 1 || col < 0 || col > grid[0].size() - 1 || grid[row][col] == '0')
        {
            return;
        }

        grid[row][col] = '0';

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};