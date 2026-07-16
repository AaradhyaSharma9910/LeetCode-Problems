#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int mx = 0;

        // Compute prefix GCDs with the maximum element seen so far
        for (auto &n : A) {
            mx = std::max(mx, n);
            n = std::gcd(n, mx);
        }

        // Sort the array
        sort(A.begin(), A.end());

        long long res = 0;

        // Sum of gcd of formed pairs
        int i = 0;
        int j = (int)A.size() - 1;

        while (i < j) {
            res += std::gcd(A[i], A[j]);
            i++;
            j--;
        }

        return res;
    }
};