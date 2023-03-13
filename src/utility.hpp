#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <sstream>

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

    vector<string> split(string const &input, const char delim)
    {
        vector<string> res;
        stringstream ss(input);
        string word;

        while (getline(ss, word, delim))
        {
            res.push_back(word);
        }

        return res;
    }

    vector<string> split_by_whitespace(string const &input)
    {
        vector<string> res;
        istringstream ss(input);

        for (string word; ss >> word;)
        {
            res.push_back(word);
        }

        return res;
    }
};