/*
    Given a sorted integer array arr, two integers k and x, return the k closest integers to x in
    the array. The result should also be sorted in ascending order.

    An integer a is closer to x than an integer b if:
    1) |a - x| < |b - x|, or
    2) |a - x| == |b - x| and a < b
*/
#include <vector>

using namespace std;

class Solution
{
public:
    /*
        Sorting method
        - Time complexity: O(NlogN + klogk)
        - Space complexity: O(1)
    */
    vector<int> findClosestElements_sort(vector<int> &arr, int k, int x)
    {
        stable_sort(begin(arr), end(arr), [x](int a, int b)
                    { return abs(a - x) < abs(b - x); });

        arr.resize(k);
        sort(arr.begin(), arr.end());

        return arr;
    }

    /*
        Two pointer method
        - Time complexity: O(N - k)
        - Space complexity: O(1)
    */
    vector<int> findClosestElements_tp(vector<int> &arr, int k, int x)
    {
        int left = 0;
        int right = arr.size() - 1;

        // Shrink the range from right & left pointer to size K
        while (right - left >= k)
        {
            if (arr[right] - x >= x - arr[left])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return vector<int>(begin(arr) + left, begin(arr) + right + 1);
    }

    /*
        Binary search method
        - Time complexity: O(logN + k)
        - Space complexity: O(1)
    */
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int size = arr.size();
        int right = lower_bound(arr.begin(), arr.end(), x) - begin(arr);
        int left = right - 1;

        while (k > 0)
        {
            // Expand the range from right & left pointer to size K
            if (right >= size || (left >= 0 && x - arr[left] <= arr[right] - x))
            {
                left--;
            }
            else
            {
                right++;
            }
            k--;
        }

        return vector<int>(begin(arr) + left + 1, begin(arr) + right);
    }
};