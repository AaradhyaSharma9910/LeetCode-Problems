
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        nth_element(nums.begin(), nums.begin() + mid, nums.end());

        int med = nums[mid];
        int moves = 0;

        for (int x : nums) {
            moves += abs(x - med);
        }

        return moves;
    }
};
