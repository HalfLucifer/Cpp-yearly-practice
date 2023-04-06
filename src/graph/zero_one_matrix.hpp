/*
    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

    The distance between two adjacent cells is 1.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto d : DIR)
            {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr < 0 || nr > mat.size() - 1 || nc < 0 || nc > mat[0].size() - 1 || mat[nr][nc] != -1)
                {
                    continue;
                }

                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }

        return mat;
    }
};