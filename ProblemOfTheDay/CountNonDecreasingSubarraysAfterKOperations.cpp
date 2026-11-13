
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<int> nextGreater(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (!st.empty())
                nextGreater[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (left <= right) {
                long long cost = 0;
                int mx = nums[right];

                for (int i = left; i <= right; ) {
                    int j = nextGreater[i];

                    if (j > right) j = right + 1;

                    long long sum = pref[j] - pref[i];

                    cost += 1LL * mx * (j - i) - sum;

                    if (cost > k) break;

                    i = j;
                }

                if (cost <= k) break;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
