/*
    You are given an array routes representing bus routes where routes[i] is a bus route that 
    the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 
    1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever. You will start at the bus stop source (You 
    are not on any bus initially), and you want to go to the bus stop target. You can travel 
    between bus stops by buses only.

    Return the least number of buses you must take to travel from source to target. 
    Return -1 if it is not possible.
*/
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, vector<int>> stop_to_routes;

        // Build a stop-to-route map
        for (int i = 0; i < routes.size(); i++)
        {
            for (int j : routes[i])
            {
                stop_to_routes[j].push_back(i);
            }
        }

        unordered_set<int> visited_stop(source);
        unordered_set<int> visited_route;

        int res = 0;

        // BFS from the source stop
        queue<int> queue;
        queue.push(source);

        while (!queue.empty())
        {
            // Traverse by level
            int size = queue.size();

            for (int k = 0; k < size; k++)
            {
                int curr = queue.front();
                queue.pop();

                // Reached the destination stop
                if (curr == target)
                {
                    return res;
                }

                for (int i : stop_to_routes[curr])
                {
                    if (visited_route.find(i) == visited_route.end())
                    {
                        // Prune the visited routes
                        visited_route.insert(i);

                        for (int j : routes[i])
                        {
                            if (visited_stop.find(j) == visited_stop.end())
                            {
                                visited_stop.insert(j);
                                queue.push(j);
                            }
                        }
                    }
                }
            }

            res++;
        }

        return -1;
    }
};