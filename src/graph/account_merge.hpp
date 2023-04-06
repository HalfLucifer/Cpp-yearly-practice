/*
    Given a list of accounts where each element accounts[i] is a list of strings, where
    the first element accounts[i][0] is a name, and the rest of the elements are emails
    representing emails of the account. Now, we would like to merge these accounts.

    After merging the accounts, return the accounts in the following format: the first
    element of each account is the name, and the rest of the elements are emails in
    sorted order. The accounts themselves can be returned in any order.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint set union
struct DSU
{
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node)
    {
        while (node != parent[node])
        {
            node = parent[node];
        }
        return node;
    }

    void join(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        parent[pa] = pb;
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int recordSize = accounts.size();
        // Disjoint set to union record id
        DSU dsu(recordSize);
        // Map email to record id
        unordered_map<string, int> email_to_id;

        for (int i = 0; i < recordSize; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];

                if (email_to_id.find(email) == email_to_id.end())
                {
                    email_to_id[email] = i;
                }
                else
                {
                    // Union ids if email is already existed
                    dsu.join(i, email_to_id[email]);
                }
            }
        }

        vector<vector<string>> mails(recordSize);

        // Proceed emails via email-to-id map
        for (auto &[email, id] : email_to_id)
        {
            // Find the pareent for each id
            int parent = dsu.find(id);
            // Push email to its owner
            mails[parent].push_back(email);
        }

        vector<vector<string>> res;

        for (int i = 0; i < recordSize; i++)
        {
            if (!mails[i].empty())
            {
                // Sort emails in ascending order
                sort(mails[i].begin(), mails[i].end());
                // Insert owner's name to head
                mails[i].insert(mails[i].begin(), accounts[i][0]);
                // Push to result vector
                res.push_back(mails[i]);
            }
        }

        return res;
    }
};