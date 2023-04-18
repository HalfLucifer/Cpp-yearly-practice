/*
    There is a new alien language which uses the latin alphabet. However, the order among letters are 
    unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted 
    lexicographically by the rules of this new language. Derive the order of letters in this language.
*/
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        set<pair<char, char>> adj;
        unordered_set<char> chars;
        unordered_map<char, int> indegree;

        // Build character set
        for (auto word : words)
        {
            chars.insert(word.begin(), word.end());
        }

        // Compare every adjacent pairs to build adjacency list
        for (int i = 0; i < words.size() - 1; i++)
        {
            int min_length = min(words[i].size(), words[i + 1].size());

            for (int j = 0; j < min_length; j++)
            {
                // Insert a pair of characters to ordered set if they are not equal
                if (words[i][j] != words[i + 1][j])
                {
                    adj.insert({words[i][j], words[i + 1][j]});
                    break;
                }
            }
        }

        // Calculate indegree for adjacency list
        for (auto &[src, dst] : adj)
        {
            indegree[dst]++;
        }

        string res;
        queue<char> q;

        for (auto c : chars)
        {
            // Push zero indegree character to queue and result string
            if (indegree[c] == 0)
            {
                q.push(c);
                res += c;
            }
        }

        // BFS for each character
        while (!q.empty())
        {
            char curr = q.front();
            q.pop();

            for (auto &[src, dst] : adj)
            {
                if (src == curr)
                {
                    indegree[dst]--;

                    if (indegree[dst] == 0)
                    {
                        q.push(dst);
                        res += dst;
                    }
                }
            }
        }

        return res;
    }
};