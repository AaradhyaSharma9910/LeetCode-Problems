#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        
        int ans = INT_MAX;
        for(auto num:nums){
            int sum = digitSum(num);
            ans = min(ans,sum);
        }
        return ans;
    }
};