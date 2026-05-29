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
/*
APPROACH - So what we did here is that first we calculated the sum of the digits seprately 
by making a function named digitSum then we created another function minElement in which we 
calculated the minimum number that we got after calculting the sum of the digits
Time Complexity is = O(n*d) where d is digit and since digit is constant so its 
time complexity is approximately equal to O(n)
Space Complexity = O(1)
*/