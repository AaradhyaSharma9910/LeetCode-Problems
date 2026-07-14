#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int n;
    int dp[201][201][201];

    int mygcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == n) {
            return (g1 != 0 && g1 == g2);
        }

        int &ans = dp[idx][g1][g2];
        if (ans != -1)
            return ans;

        ans = solve(idx + 1, g1, g2, nums);

        int ng1 = (g1 == 0) ? nums[idx] : mygcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, ng1, g2, nums)) % MOD;

        int ng2 = (g2 == 0) ? nums[idx] : mygcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, ng2, nums)) % MOD;

        return ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};