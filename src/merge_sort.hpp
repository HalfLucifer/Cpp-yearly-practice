#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
        {
            return;
        }

        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        
        merge(nums, low, mid, high);
    }

    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;

        // Sort [low..mid] & [mid+1..high]
        while (i <= mid && j <= high)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        // Place the remaining parts
        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }
        while (j <= high)
        {
            temp[k++] = nums[j++];
        }

        // Copy to nums from low to high
        for (int p = 0; p < k; p++)
        {
            nums[low + p] = temp[p];
        }
    }
};