/*
    The next permutation of an array of integers is the next lexicographically greater 
    permutation of its integer. More formally, if all the permutations of the array are 
    sorted in one container according to their lexicographical order, then the next 
    permutation of that array is the permutation that follows it in the sorted container. 
    
    If such arrangement is not possible, the array must be rearranged as the lowest 
    possible order (i.e., sorted in ascending order).
*/
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int left = nums.size() - 1;

        // Find the ascending pivot in reverse order
        while (left > 0 && nums[left] <= nums[left - 1])
        {
            left--;
        }

        // All sorted in descending order
        if (left == 0)
        {
            // Reverse (or sort) to produce the lowest permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        // Move to the pivot index
        left--;

        int right = nums.size() - 1;

        // Find the first element >= pivot
        while (right > left && nums[right] <= nums[left])
        {
            right--;
        }

        // Swap them for the next larger permutation
        swap(nums[left], nums[right]);

        // Reverse/sort the remaining elements
        reverse(nums.begin() + left + 1, nums.end());

        return;
    }
};
