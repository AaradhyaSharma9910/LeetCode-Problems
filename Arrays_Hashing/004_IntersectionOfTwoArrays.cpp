#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        vector<int>result;
        for(int num:nums2)
        {
            if(s.find(num)!=s.end())
            {
                result.push_back(num);
                s.erase(num);
            }
        }
        return result;
        
    }
};