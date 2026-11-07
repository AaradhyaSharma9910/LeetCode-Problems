
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        // {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> idle;

        // {available_time, index}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        for (int i = 0; i < m; i++) {
            idle.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < n; i++) {
            time = max(time, (long long)i);

            // Release all available servers
            while (!busy.empty() && busy.top().first <= time) {
                auto curr = busy.top();
                busy.pop();

                idle.push({servers[curr.second], curr.second});
            }

            // If no server is idle, advance time
            if (idle.empty()) {
                time = busy.top().first;

                while (!busy.empty() && busy.top().first <= time) {
                    auto curr = busy.top();
                    busy.pop();

                    idle.push({servers[curr.second], curr.second});
                }
            }

            // Select the best available server
            auto curr = idle.top();
            idle.pop();

            int idx = curr.second;

            ans.push_back(idx);

            // Mark server as busy
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};
