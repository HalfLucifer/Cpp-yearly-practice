/*
    Given an array of strings words and an integer k, return the k most frequent strings.

    Return the answer sorted by the frequency from highest to lowest. Sort the words with the same
    frequency by their lexicographical order.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;

        for (auto w : words)
        {
            mp[w]++;
        }

        auto cmp = [](pair<int, string> a, pair<int, string> b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto [key, val] : mp)
        {
            pq.push({val, key});
        }

        vector<string> res;

        while (!pq.empty() && k > 0)
        {
            auto [_, word] = pq.top();
            pq.pop();
            res.push_back(word);
            k--;
        }

        return res;
    }
};