/*
    Insert newInterval into intervals such that intervals is still sorted in ascending
    order by starti and intervals still does not have any overlapping intervals (merge
    overlapping intervals if necessary)
*/
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int start = newInterval[0];
        int end = newInterval[1];
        int curr = 0;
        int len = intervals.size();

        // Handle intervals end before the new interval
        while (curr < len && intervals[curr][1] < start)
        {
            res.push_back(intervals[curr]);
            curr++;
        }

        // Handle overlapped intervals
        while (curr < len && !(intervals[curr][0] > end))
        {
            start = min(start, intervals[curr][0]);
            end = max(end, intervals[curr][1]);
            curr++;
        }
        res.push_back({start, end});

        // Handle intervals start after the new interval
        while (curr < len)
        {
            res.push_back(intervals[curr]);
            curr++;
        }

        return res;
    }
};