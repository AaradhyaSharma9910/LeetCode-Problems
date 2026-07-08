#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int MOD = 1000000007;
    static constexpr int MAX = 100001;

    static int p10[MAX];
    static bool initialized;

    static void init() {
        if (initialized) return;
        initialized = true;

        p10[0] = 1;
        for (int i = 1; i < MAX; i++) {
            p10[i] = (1LL * p10[i - 1] * 10) % MOD;
        }
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        init();

        int n = s.length();

        vector<int> A(n + 1, 0);
        vector<int> B(n + 1, 0);
        vector<int> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            A[i + 1] = A[i] + d;

            if (d != 0) {
                B[i + 1] = (1LL * B[i] * 10 + d) % MOD;
                len[i + 1] = len[i] + 1;
            } else {
                B[i + 1] = B[i];
                len[i + 1] = len[i];
            }
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1] + 1;

            long long sub = 1LL * B[l] * p10[len[r] - len[l]] % MOD;
            long long x = (B[r] - sub + MOD) % MOD;

            res.push_back((1LL * x * (A[r] - A[l])) % MOD);
        }

        return res;
    }
};

int Solution::p10[Solution::MAX];
bool Solution::initialized = false;