#include <vector>

using namespace std;

class Solution
{
public:
    // Bellman-Ford algorithm
    // int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    auto findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) -> int
    {
        vector<int> res(n, INT_MAX);
        res[src] = 0;

        // K stops means K+1 nodes (iterations) are required
        for (int i = 0; i <= k; i++)
        {
            // Save previous result for updating next result
            vector<int> curr(res);

            for (auto &f : flights)
            {
                int from = f[0];
                int to = f[1];
                int price = f[2];

                if (res[from] != INT_MAX)
                {
                    curr[to] = min(curr[to], res[from] + price);
                }
            }

            res = curr;
        }

        return res[dst] == INT_MAX ? -1 : res[dst];
    }

    // 2D dynamic programming
    int findCheapestPrice_DP(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // dp[i][j] is the min cost for (i-1) stop to j destination
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));

        // Base case: cost of src=0
        for (int i = 0; i <= k + 1; i++)
        {
            dp[i][src] = 0;
        }

        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &f : flights)
            {
                int from = f[0];
                int to = f[1];
                int price = f[2];

                if (dp[i - 1][from] != INT_MAX)
                {
                    dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
                }
            }
        }

        return (dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst]);
    }
};
