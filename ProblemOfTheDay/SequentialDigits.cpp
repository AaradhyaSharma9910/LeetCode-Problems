#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int q[45];
    static bool init;

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int x : q) {
            if (x >= low && x <= high)
                res.push_back(x);
        }

        return res;
    }
};

// Static member definitions
int Solution::q[45];

bool Solution::init = []() {
    int n = 0;

    for (int i = 1; i < 10; i++)
        Solution::q[n++] = i;

    for (int i = 0; i < n; i++) {
        int d = Solution::q[i] % 10;
        if (d < 9)
            Solution::q[n++] = Solution::q[i] * 10 + d + 1;
    }

    return true;
}();