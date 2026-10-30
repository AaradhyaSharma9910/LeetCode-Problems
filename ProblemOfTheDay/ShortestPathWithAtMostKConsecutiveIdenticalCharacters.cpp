#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back(make_pair(e[1], e[2]));
        }

        vector<vector<long long>> dis(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dis[0][1] = 0;
        pq.push(make_tuple(0, 0, 1));

        while (!pq.empty()) {

            long long d = get<0>(pq.top());
            int x = get<1>(pq.top());
            int cnt = get<2>(pq.top());

            pq.pop();

            if (d != dis[x][cnt]) {
                continue;
            }

            if (x == n - 1) {
                return (int)d;
            }

            for (auto edge : g[x]) {

                int y = edge.first;
                int w = edge.second;

                int new_cnt;

                if (labels[x] == labels[y]) {
                    new_cnt = cnt + 1;
                } 
                else {
                    new_cnt = 1;
                }

                if (new_cnt > k) {
                    continue;
                }

                long long nd = d + w;

                if (nd < dis[y][new_cnt]) {
                    dis[y][new_cnt] = nd;
                    pq.push(make_tuple(nd, y, new_cnt));
                }
            }
        }

        return -1;
    }
};