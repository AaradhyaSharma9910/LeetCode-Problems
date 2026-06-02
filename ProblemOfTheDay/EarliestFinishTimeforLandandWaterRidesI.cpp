/*
Approach:
There are two possible orders to complete the rides:

1. Land -> Water
   - First, find the earliest time at which any land ride can finish.
   - For each water ride, start it at:
        max(earliestLandFinish, waterStartTime[i])
   - Calculate its finish time and keep the minimum.

2. Water -> Land
   - First, find the earliest time at which any water ride can finish.
   - For each land ride, start it at:
        max(earliestWaterFinish, landStartTime[i])
   - Calculate its finish time and keep the minimum.

The answer is the minimum completion time among both possible orders.

Time Complexity:
O(n + m)
- One pass to find earliest land finish.
- One pass to find earliest water finish and Land -> Water answer.
- One pass to find Water -> Land answer.

Space Complexity:
O(1)
- Only a few variables are used.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int land = INT_MAX;
        int water = INT_MAX;
        int land_water = INT_MAX;
        int water_land = INT_MAX;
        for(int i = 0; i < n; i++){
        land = min(land,landStartTime[i]+landDuration[i]);
    }
    for(int i = 0; i < m; i++){
        water = min(water,waterStartTime[i]+waterDuration[i]);
        land_water = min(land_water,max(waterStartTime[i],land)+waterDuration[i]);
    }
    for(int i = 0; i < n; i++){
        water_land = min(water_land,max(landStartTime[i],water)+landDuration[i]);
    }
    return min(water_land,land_water);
    }
};