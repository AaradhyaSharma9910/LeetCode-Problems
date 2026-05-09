#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int reverse = 0;
        while(n > 0)
        {
            int remainder = n % 10;
            reverse = reverse * 10 + remainder;
            n = n / 10;
        }
        return abs(original-reverse);
    }
};