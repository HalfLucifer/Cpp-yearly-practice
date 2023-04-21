#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int getFood(vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '*')
                {
                    q.push({i, j});
                }
            }
        }

        int res = 0;
        vector<pair<int, int>> DIR{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [row, col] = q.front();
                q.pop();

                if (grid[row][col] == '#')
                {
                    return res;
                }

                for (auto d : DIR)
                {
                    int r = row + d.first;
                    int c = col + d.second;

                    if (r < 0 || r > grid.size() - 1 || c < 0 || c > grid[0].size() - 1 || grid[r][c] == 'X')
                    {
                        continue;
                    }

                    q.push({r, c});
                }

                grid[row][col] = 'X';
            }

            res++;
        }

        return -1;
    }
};