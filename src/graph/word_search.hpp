#include <vector>
#include <string>

using namespace std;

class Solution
{
    bool dfs(int row, int col, int n, vector<vector<char>> &board, string word)
    {
        if (n == word.size())
        {
            return true;
        }

        if (row < 0 || row > board.size() - 1 || col < 0 || col > board[0].size() - 1 || board[row][col] != word[n])
        {
            return false;
        }

        // Mark the character as visited
        board[row][col] = '#';

        bool res = dfs(row + 1, col, n + 1, board, word) ||
                   dfs(row - 1, col, n + 1, board, word) ||
                   dfs(row, col + 1, n + 1, board, word) ||
                   dfs(row, col - 1, n + 1, board, word);

        // Unmark the character
        board[row][col] = word[n];

        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // Proceed DFS only when the fist character is matched
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
