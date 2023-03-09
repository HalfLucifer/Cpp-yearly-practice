#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> data;

        for (auto i : intervals)
        {
            data.push_back({i[0], 1});  // Mark starting as 1
            data.push_back({i[1], -1}); // Mark ending as -1
        }

        sort(data.begin(), data.end(), cmp);

        vector<vector<int>> res;
        int curr = 0;
        int start = 0;
        int end = 0;

        for (auto interval : data)
        {
            if (curr == 0 && interval.second > 0)
            {
                // Found a starting point
                start = interval.first;
            }
            else if (curr > 0 && (curr + interval.second == 0))
            {
                // Found a ending point
                end = interval.first;
                res.push_back({start, end});
            }

            // Update start/end status
            curr += interval.second;
        }

        return res;
    }
};