/*
    There are n flights that are labeled from 1 to n. You are given an array of flight bookings
    bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti
    through lasti (inclusive) with seatsi seats reserved for each flight in the range.

    Return an array answer of length n, where answer[i] is the total number of seats reserved for
    flight i.
*/
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n, 0);

        for (auto b : bookings)
        {
            int i = b[0] - 1;
            int j = b[1] - 1;
            int val = b[2];

            // To update value in a difference array
            //   1) add value in start index
            //   2) subtract value in end+1 index
            diff[i] += val;

            if (j + 1 < n)
            {
                diff[j + 1] -= val;
            }
        }

        // Rebuild the original array by difference array
        vector<int> res(n);
        res[0] = diff[0];

        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] + diff[i];
        }

        return res;
    }
};