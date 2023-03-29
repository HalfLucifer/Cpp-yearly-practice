/*
    Given a characters array tasks, representing the tasks a CPU needs to do, where each letter
    represents a different task. Tasks could be done in any order. Each task is done in one unit
    of time. For each unit of time, the CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown period between two same
    tasks (the same letter in the array), that is that there must be at least n units of time between
    any two same tasks. Return the least number of units of times that the CPU will take to finish
    all the given tasks.
*/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // Compute task counts
        unordered_map<char, int> mp;
        for (auto c : tasks)
        {
            mp[c]++;
        }

        // Push task counts to priority queue
        // NOTE: To compute total time required, task characters are not required
        priority_queue<int> pq;
        for (auto &[key, val] : mp)
        {
            pq.push(val);
        }

        int idleTime = 0;
        
        while (!pq.empty())
        {
            int cycle = n + 1; // CPU cycle = cooldown + 1
            vector<int> doneTask;

            // Try to proceed each task within a CPU cycle
            while (cycle > 0 && !pq.empty())
            {
                int task = pq.top();
                pq.pop();

                // Push back for next CPU cycle if task is not finished
                if (task > 1) {
                    doneTask.push_back(task - 1);
                }

                // Decrease the available time
                cycle--;
            }

            // Push remaining tasks back to priority queue
            for (auto task : doneTask)
            {
                pq.push(task);
            }

            // If priority queue is not empty, the remaining cycle is the idle time to append
            if (!pq.empty()) {
                idleTime += cycle;
            }
        }

        return idleTime + tasks.size();
    }
};