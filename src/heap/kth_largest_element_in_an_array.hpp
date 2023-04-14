/*
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Build a min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto n : nums)
        {
            pq.push(n);

            // Keep only k elements in priority queue
            if (pq.size() > k)
            {
                // Remove the smallest element
                pq.pop();
            }
        }

        return pq.top();
    }
};