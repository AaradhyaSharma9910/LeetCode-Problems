#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int mx = 0;

        for (auto &n : A) {
            mx = max(mx, n);
            n = __gcd(n, mx);
        }

        sort(A.begin(), A.end());

        long long res = 0;
        int i = 0;
        int j = (int)A.size() - 1;

        while (i < j) {
            res += __gcd(A[i], A[j]);
            i++;
            j--;
        }

        return res;
    }
};