/*
Approach:
1. Traverse from left to right and store the sum of all elements
   to the left of each index in the answer array.
2. Traverse from right to left while maintaining the right-side sum.
3. For each index, compute:
      abs(leftSum - rightSum)
   and store it in the answer array.
4. Return the resulting array.

Example:
nums = [10,4,8,3]

Left sums  = [0,10,14,22]
Right sums = [15,11,3,0]

Answer = [15,1,11,22]

Time Complexity: O(n)
- Two linear traversals of the array.

Space Complexity: O(1) Auxiliary Space
- Excluding the output array.
- The answer vector is required for the result.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};