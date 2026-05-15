#include<bits/stdc++.h>
using namespace std;
// Idea: Store maximum till each index (prefix max) and minimum from each index to end (suffix min)
// If left side max > right side min, current partition is invalid so inherit next answer
// Time Complexity: O(n) -> single traversal for prefix/suffix + single traversal for answer array
// Space Complexity: O(n) -> extra prefix max, suffix min, and answer arrays used

class Solution {
public:
    static vector<int> maxValue(vector<int>& nums) {
        const int n=nums.size();
        vector<int> prefMax(n), sufMin(n);// vector option
        prefMax[0]=nums[0];
        sufMin[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            const int x=nums[i], y=nums[n-1-i];
            prefMax[i]=max(prefMax[i-1], x);
            sufMin[n-1-i]=min(sufMin[n-i], y);
        }
        vector<int> ans(n);
        ans[n-1]=prefMax[n-1];
        for(int i=n-2; i>=0; i--){
            if (prefMax[i]>sufMin[i+1]) 
                ans[i]=ans[i+1];
            else ans[i]=prefMax[i];
        }
        return ans;
    }
};