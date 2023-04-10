#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int dict[26] = {0};

        for (char ch : magazine)
        {
            dict[ch - 'a']++;
        }

        for (char ch : ransomNote)
        {
            if (dict[ch - 'a'] > 0)
            {
                dict[ch - 'a']--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};