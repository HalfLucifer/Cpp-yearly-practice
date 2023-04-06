/*
    To perform a flood fill, consider the starting pixel, plus any pixels connected 
    4-directionally to the starting pixel of the same color as the starting pixel, 
    plus any pixels connected 4-directionally to those pixels (also with the same color), 
    and so on. Replace the color of all of the aforementioned pixels with color.

    Return the modified image after performing the flood fill.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &image, int row, int col, int curr_color, int target_color)
    {
        if (row < 0 || row > image.size() - 1 || col < 0 || col > image[0].size() - 1 || image[row][col] == target_color || image[row][col] != curr_color)
        {
            return;
        }

        image[row][col] = target_color;

        dfs(image, row + 1, col, curr_color, target_color);
        dfs(image, row - 1, col, curr_color, target_color);
        dfs(image, row, col + 1, curr_color, target_color);
        dfs(image, row, col - 1, curr_color, target_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int curr = image[sr][sc];
        dfs(image, sr, sc, curr, color);
        return image;
    }

    vector<vector<int>> floodFill_BFS(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int curr = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            if (image[row][col] == curr && image[row][col] != color)
            {
                image[row][col] = color;

                for (auto d : DIR)
                {
                    int r = row + d.first;
                    int c = col + d.second;

                    if (r >= 0 && r <= image.size() - 1 && c >= 0 && c <= image[0].size() - 1)
                    {
                        q.push({r, c});
                    }
                }
            }
        }

        return image;
    }
};