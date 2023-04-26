#include <vector>
#include <string>

using namespace std;

struct TrieNode
{
    TrieNode *children[26] = {};
    string *word;

    void addWord(string &word)
    {
        TrieNode *curr = this;

        for (char c : word)
        {
            c -= 'a';
            if (curr->children[c] == nullptr)
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        curr->word = &word;
    }
};

class Solution
{
    vector<string> res;

    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *node)
    {
        if (row < 0 || row > board.size() - 1 || col < 0 || col > board[0].size() - 1)
        {
            return;
        }

        char curr = board[row][col];
        if (curr == '#' || node->children[curr - 'a'] == nullptr)
        {
            return;
        }

        // Move to child node
        node = node->children[curr - 'a'];

        // Reach the end of Trie
        if (node->word != nullptr)
        {
            // Matched word is found
            res.push_back(*node->word);
            // Erase word to prevent from visiting again
            node->word = nullptr;
        }

        // Mark as visited
        board[row][col] = '#';

        dfs(board, row + 1, col, node);
        dfs(board, row - 1, col, node);
        dfs(board, row, col + 1, node);
        dfs(board, row, col - 1, node);

        // Unmark the visited character
        board[row][col] = curr;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode trieNode;
        for (auto &s : words)
        {
            trieNode.addWord(s);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, &trieNode);
            }
        }

        return res;
    }
};