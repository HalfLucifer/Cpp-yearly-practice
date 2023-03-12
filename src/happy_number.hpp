#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;

        while (true)
        {
            string s = std::to_string(n);
            n = 0;

            for (char ch : s)
            {
                n += (ch - '0') * (ch - '0');
            }

            if (n == 1)
            {
                return true;
            }

            if (set.count(n) > 0)
            {
                return false;
            }

            set.insert(n);
        }
    }
};