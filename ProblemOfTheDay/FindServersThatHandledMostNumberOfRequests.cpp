
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Job {
        int at;
        int server;

        bool operator>(const Job& other) const {
            if (at != other.at)
                return at > other.at;
            return server > other.server;
        }
    };

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Free servers: {next available turn}
        priority_queue<int, vector<int>, greater<int>> free;

        for (int i = 0; i < k; i++) {
            free.push(i);
        }

        // Busy servers: {finish time, server index}
        priority_queue<Job, vector<Job>, greater<Job>> busy;

        vector<int> handled(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {

            // Release servers whose tasks are completed
            while (!busy.empty() && busy.top().at <= arrival[i]) {

                int x = busy.top().server;
                busy.pop();

                // Calculate the server's next available turn
                free.push(i + (x - i % k + k) % k);
            }

            // No server available
            if (free.empty())
                continue;

            // Select the server with the smallest valid turn
            int x = free.top() % k;
            free.pop();

            // Assign request to server
            busy.push({arrival[i] + load[i], x});

            handled[x]++;
        }

        // Find maximum number of requests handled
        int most = *max_element(handled.begin(), handled.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (handled[i] == most)
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int k = 3;
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};

    vector<int> ans = sol.busiestServers(k, arrival, load);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
