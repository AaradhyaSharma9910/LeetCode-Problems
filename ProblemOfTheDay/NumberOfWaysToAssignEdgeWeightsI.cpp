#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static constexpr long long MOD = 1e9 + 7;
typedef long long ll;
ll power(ll base, ll exponent){
    if(exponent == 0){
        return 1;
    }
    ll half = power(base,exponent/2);
    ll result = (half*half)%MOD;
    if(exponent%2==1){
        result = (result * base)%MOD;
    }
    return result;
}
int getMaxDepth(unordered_map<int,vector<int>>& adj,int node, int parent){
    int depth = 0;
    for(int neighbour : adj[node]){
        if(neighbour==parent)continue;
        depth = max(depth,getMaxDepth(adj,neighbour,node)+1);
    }
    return depth;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d = getMaxDepth(adj,1,-1);
        return power(2,d-1);
        }
};
    