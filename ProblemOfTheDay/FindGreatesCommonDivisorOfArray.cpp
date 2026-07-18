#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return GCD(mx, mn);
    }
};