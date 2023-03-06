#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i=0; i < nums.size(); i++) {
            int curr = target - nums[i];

            if (map.find(curr) != map.end()) {
                return {map[curr], i};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};