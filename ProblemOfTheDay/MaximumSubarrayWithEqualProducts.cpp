
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long findGCD(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int res = 1;

        for (int i = 0; i < nums.size(); i++) {
            long long prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];

            for (int j = i + 1; j < nums.size(); j++) {

                prodVal *= nums[j];

                gcdVal = findGCD(gcdVal, nums[j]);

                lcmVal = (lcmVal / findGCD(lcmVal, nums[j])) * nums[j];

                if (prodVal == gcdVal * lcmVal) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
