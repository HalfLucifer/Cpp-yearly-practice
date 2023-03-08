#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Utility
{
public:
    int max(vector<int> &input)
    {
        return *max_element(input.begin(), input.end());
    }

    int min(vector<int> &input)
    {
        return *min_element(input.begin(), input.end());
    }

    int scaleMaxElement(vector<int> &input, int scale)
    {
        vector<int>::iterator it = max_element(input.begin(), input.end());
        *it *= scale;
        return *it;
    }

    int sum(vector<int> &input)
    {
        return accumulate(input.begin(), input.end(), 0);
    }
};