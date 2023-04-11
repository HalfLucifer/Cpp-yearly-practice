/*
    Given an array of meeting time intervals consisting of start and end times
    [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
*/
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    bool canAttendMeeting(vector<Interval> &intervals)
    {
        vector<pair<int, int>> queue;

        for (int i = 0; i < intervals.size(); i++)
        {
            queue.push_back({intervals[i].start, 1});
            queue.push_back({intervals[i].end, -1});
        }

        sort(queue.begin(), queue.end());

        int res = 0;
        for (int i = 0; i < queue.size(); i++)
        {
            res += queue[i].second;

            if (res > 1)
            {
                return false;
            }
        }

        return true;
    }
};