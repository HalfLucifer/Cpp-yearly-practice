/*
    In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at
    square [0, 0]. A knight has 8 possible moves it can make, as illustrated below. Each move is
    two squares in a cardinal direction, then one square in an orthogonal direction.

    Return the minimum number of steps needed to move the knight to the square [x, y]. It is
    guaranteed the answer exists.
*/
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int minKnightMoves(int x, int y)
    {
        // 8 possible moves
        vector<pair<int, int>> DIR = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {2, -1}, {1, -2}};

        // Only need to check in (+, +) quadrant
        x = abs(x);
        y = abs(y);

        set<pair<int, int>> visited;
        queue<pair<int, int>> q;

        // Push the origin to queue
        q.push({0, 0});
        int res = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [cx, cy] = q.front();
                q.pop();

                // Reached the goal
                if (cx == x && cy == y)
                {
                    return res;
                }

                for (auto [dx, dy] : DIR)
                {
                    int next_x = cx + dx;
                    int next_y = cy + dy;

                    // Check whether new position is unvisited and larger than (-2, -2)
                    if (visited.count({next_x, next_y}) == 0 && next_x >= -2 && next_y >= -2)
                    {
                        visited.insert({next_x, next_y});
                        q.push({next_x, next_y});
                    }
                }
            }

            res++;
        }

        return res;
    }
};