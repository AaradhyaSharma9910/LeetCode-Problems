/*
Approach:
1. For the first set of rides, find the earliest possible finishing time
   (start time + duration).
2. Assume we finish the first ride at this earliest time.
3. For every ride in the second set:
   - The ride can start only after both:
       a) we finish the first ride, and
       b) the ride's own start time.
   - Therefore, actual start time = max(finish1, start2[i]).
   - Finish time = actual start time + duration2[i].
4. Take the minimum finish time among all second rides.
5. Compute the answer for:
      Land -> Water
      Water -> Land
   and return the smaller of the two.

Time Complexity:
- Finding earliest finish time of first set: O(n)
- Checking all rides of second set: O(m)
- Total for one call: O(n + m)
- Since the function is called twice:
  O(n + m)

Space Complexity:
- O(1)
  Only a few integer variables are used.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findFinishTime(vector<int>& start1,vector<int>& duration1,vector<int>& start2,vector<int>& duration2){
    int finish1 = INT_MAX;
    for(int i = 0; i < start1.size(); i++){
        finish1 = min(finish1,start1[i]+duration1[i]);
    }
     int finish2 = INT_MAX;
    for(int i = 0; i < start2.size(); i++){
        finish2 = min(finish2,max(finish1,start2[i])+duration2[i]);
    }
    return finish2;
}

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = findFinishTime(landStartTime,landDuration,waterStartTime,waterDuration);
        int water_land = findFinishTime(waterStartTime,waterDuration,landStartTime,landDuration);
    
        return min(land_water,water_land);
    
        
    }
};