
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lo = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int x : nums) {
            moves += x - lo;
        }

        return moves;
    }
};
