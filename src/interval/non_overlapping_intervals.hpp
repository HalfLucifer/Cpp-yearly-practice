/*
    Given an array of intervals intervals where intervals[i] = [starti, endi], return the 
    minimum number of intervals you need to remove to make the rest of the intervals 
    non-overlapping.
*/
#include <vector>

using namespace std;

class Solution
{
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
                res++;
            }
        }

        return res;
    }
};
