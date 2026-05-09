#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        // Step 1: map value -> indices 
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        //Step 2: process each query 
        for(int q: queries){
            int val=nums[q];
            vector<int>& v=mp[val];

            //if only one occurrence
            if(v.size()==1){
                ans.push_back(-1);
                continue;
            }
            //binary search
            int pos= lower_bound(v.begin(),v.end(),q) - v.begin();
            int res = INT_MAX;

            //check left neighbor
            int left = (pos - 1 + v.size())% v.size();
            int leftIdx = v[left];
            int distLeft = abs(q - leftIdx);
            distLeft = min(distLeft, n-distLeft);
            //check right neighbor
            int right = (pos + 1) % v.size();
            int rightIdx = v[right];
            int distRight = abs(q-rightIdx);
            distRight = min(distRight,n-distRight);
            res = min(distLeft,distRight);
            ans.push_back(res);

        }
        return ans;
    }
};