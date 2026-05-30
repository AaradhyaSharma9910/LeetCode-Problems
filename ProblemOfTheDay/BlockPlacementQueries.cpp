/*
Approach (Offline Processing + Fenwick Tree)

Problem Idea:
- Type 1 query inserts an obstacle at position x.
- Type 2 query asks whether a block of length 'size' can fit in range [0, x].

Observation:
- Directly handling insertions and checking gaps online is difficult.
- Instead, process queries in reverse order.

Reverse Processing:
- First insert all obstacles from type 1 queries into a set.
- While traversing queries backwards:
    * A type 1 insertion becomes obstacle removal.
    * Removing an obstacle merges two adjacent gaps.
    * Type 2 queries can now be answered using the current obstacle configuration.

Data Structures:

1. Ordered Set:
   - Stores obstacle positions.
   - Helps find previous and next obstacle in O(log n).

2. Fenwick Tree (BIT):
   - Stores maximum gap length information.
   - update(pos, gap):
       Updates Fenwick tree with a gap ending at 'pos'.
   - solve(pos):
       Returns maximum gap among all gaps ending at positions <= pos.

Gap Representation:
- For every obstacle 'curr', store:
      gap = curr - previous_obstacle
- Gap value is updated at index 'curr' in the BIT.

Answering Query Type 2:
- Let prevObstacle be the nearest obstacle before x.
- Current partial gap ending at x:
      d = x - prevObstacle

Possible ways to place a block:
1. Entirely inside the current partial gap:
      d >= size

2. Inside any complete gap before x:
      maxGapBeforeX = solve(x)
      maxGapBeforeX >= size

If either condition is true, answer = true.

Complexity:
- Each set operation: O(log n)
- Each BIT update/query: O(log n)
- Total complexity: O(Q log N)

Key Insight:
Processing queries backwards converts insertions into deletions, making gap merging easy. Fenwick Tree efficiently maintains the maximum gap information needed for range queries.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
ll solve(int i, vector<ll>&bit)
{
    ll ans = 0;
    for(;i>0;i-=(i&-i)){
        ans = max(bit[i],ans);
    }
    return ans;
}
void update(int i,ll x,vector<ll>&bit)
{
    for(;i<bit.size();i+=(i&-i)){
        bit[i]=max(bit[i],x);
    }
}
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<ll>bit(50001,0);
        set<int> blocks{0};
        for(auto q:queries)
        if(q[0]==1){
            blocks.insert(q[1]);
        }
        for(auto it=next(begin(blocks));it!=end(blocks);it++){
            int curr=*it;
            int pre=*prev(it);
            update(curr,curr-pre,bit);
        }
        for(int i = queries.size()-1;i>=0;i--){
            int x = queries[i][1];
            auto it = blocks.lower_bound(x);
            if(queries[i][0]==1){
                if(next(it)!=end(blocks)){
                      update(*next(it),*next(it)-*prev(it),bit);
                }
                blocks.erase(it);
             
            }
            else{
                int size = queries[i][2];
                int d = x-*prev(it);
                if(d>=size||solve(x,bit)>=size){
                    ans.push_back(true);
                }else{
                    ans.push_back(false);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
