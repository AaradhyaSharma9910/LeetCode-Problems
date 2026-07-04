#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> root(n+1);
        iota(root.begin(), root.end(), 0);
function<int(int)> find = [&](int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
};
        for(auto& r : roads)
        root[find(r[0])] = find(r[1]);
        int res = 10001;
        for(auto&r : roads)
        if(find(r[0]) == find(1))
        res = min(res,r[2]);
        return res;
        
    }
};