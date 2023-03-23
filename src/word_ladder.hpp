#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.count(endWord) == 0)
        {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int res = 1;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                string curr = q.front();
                q.pop();

                // Found the endWord
                if (curr == endWord)
                {
                    return res;
                }

                // For each character of current word
                for (int j = 0; j < curr.length(); j++)
                {
                    string s = curr;

                    // Traverse from 'a' to 'z'
                    for (int k = 'a'; k <= 'z'; k++)
                    {
                        // Replace one character of current word
                        s[j] = k;

                        // Check if the new word is existed
                        if (dict.find(s) != dict.end())
                        {
                            // Erase to prevent from visiting twice
                            dict.erase(s);
                            // Push for next iteration
                            q.push(s);
                        }
                    }
                }
            }

            res++;
        }

        return 0;
    }
};