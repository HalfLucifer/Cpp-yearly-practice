#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>

#include "src/two_sum.hpp"

using namespace std;

int main()
{
    cout << "========== Hello CPP! ==========" << endl;

    Solution s = Solution();
    vector<int> two_sum = {1,2,3,4,5};
    vector<int> v = s.twoSum(two_sum, 6);
    cout << "two sum: (" << v[0] << ", " << v[1] << endl;

    cout << "========= See you CPP! =========" << endl;
    return 0;
}