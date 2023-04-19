/*
    Given an m x n integers matrix, return the length of the longest increasing path
    in matrix.
*/
#include <vector>

using namespace std;

class Solution
{
    int dfs(int r, int c, vector<vector<int>> &dp, vector<vector<int>> &matrix)
    {
        if (dp[r][c] > 0)
        {
            return dp[r][c];
        }

        int res = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto d : dir)
        {
            int row = r + d[0];
            int col = c + d[1];

            if (row >= 0 && row <= matrix.size() - 1 && col >= 0 && col <= matrix[0].size() - 1 && matrix[r][c] < matrix[row][col])
            {
                res = max(res, dfs(row, col, dp, matrix));
            }
        }

        // Count of longest path = count of previous longest path + 1
        dp[r][c] = res + 1;

        return dp[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        // dp[i][j] is the count of longest increasing path on matrix[i][j]
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        int res = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                res = max(res, dfs(i, j, dp, matrix));
            }
        }

        return res;
    }
};