#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto cmp = [](vector<int> a, vector<int> b)
        {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (auto pt : points)
        {
            pq.push(pt);
        }

        vector<vector<int>> res;

        for (auto i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

    vector<vector<int>> kClosest_optimized(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto pt : points)
        {
            int distance = pt[0] * pt[0] + pt[1] * pt[1];

            if (pq.size() < k)
            {
                pq.push({distance, {pt[0], pt[1]}});
            }
            else
            {
                auto [top, _] = pq.top();
                if (top > distance)
                {
                    pq.pop();
                    pq.push({distance, {pt[0], pt[1]}});
                }
            }
        }

        for (auto i = 0; i < k; i++)
        {
            if (!pq.empty())
            {
                auto [_, pt] = pq.top();
                res.push_back({pt.first, pt.second});
                pq.pop();
            }
        }

        return res;
    }
};