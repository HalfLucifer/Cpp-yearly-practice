/*
    Given an array of meeting time intervals consisting of start and end times
    [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
    required.
*/
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        map<int, int> mp; // Ordered map

        for (auto interval : intervals)
        {
            mp[interval[0]]++; // Mark +1 at the start of interval
            mp[interval[1]]--; // Mark -1 at the end of interval
        }

        int sum = 0;
        int res = 0;

        // Traverse map in order
        for (auto &[key, val] : mp)
        {
            sum += val;          // A meeting started when sum > 0
            res = max(sum, res); // Store the max
        }

        return res;
    }
};