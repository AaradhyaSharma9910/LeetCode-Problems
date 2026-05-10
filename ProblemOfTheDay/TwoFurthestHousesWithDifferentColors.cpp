#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        // Check from left (compare with first element)
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                ans = max(ans, i - 0);
                break;
            }
        }

        // Check from right (compare with last element)
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, (n - 1) - i);
                break;
            }
        }

        return ans;
    }
};