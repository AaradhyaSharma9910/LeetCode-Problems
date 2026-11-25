
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const ll MOD = 1000000007LL;
        const ll BASE = 911382323LL;

        int n = nums.size();

        vector<ll> h(n + 1, 0);
        vector<ll> p(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE + nums[i]) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }

        auto check = [&](int len) -> bool {
            unordered_map<ll, int> cnt;

            for (int l = 0; l + len <= n; l++) {
                int r = l + len;

                ll key = (h[r] - h[l] * p[len] % MOD + MOD) % MOD;

                cnt[key]++;
            }

            for (auto it = cnt.begin(); it != cnt.end(); it++) {
                if (it->second == 1) {
                    return true;
                }
            }

            return false;
        };

        int lo = 1, hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
