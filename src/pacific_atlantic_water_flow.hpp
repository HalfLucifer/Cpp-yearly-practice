#include <vector>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, int pre)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Current cell must be greater than previous cell
        if (row < 0 || row > m - 1 || col < 0 || col > n - 1 || visited[row][col] || matrix[row][col] < pre)
        {
            return;
        }

        // Mark it visited
        visited[row][col] = true;

        dfs(matrix, visited, row + 1, col, matrix[row][col]);
        dfs(matrix, visited, row - 1, col, matrix[row][col]);
        dfs(matrix, visited, row, col + 1, matrix[row][col]);
        dfs(matrix, visited, row, col - 1, matrix[row][col]);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0)
        {
            return {};
        }

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific is in the range [i, 0] and [0, i]
        // Atlantic is in the range [i, n-1] and [m-1, i]
        for (int i = 0; i < m; i++)
        {
            dfs(matrix, pacific, i, 0, INT_MIN);
            dfs(matrix, atlantic, i, n - 1, INT_MIN);
        }

        for (int i = 0; i < n; i++)
        {
            dfs(matrix, pacific, 0, i, INT_MIN);
            dfs(matrix, atlantic, m - 1, i, INT_MIN);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};