#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int num = 0;
        for(int i = 0; i<gain.size(); i++){
            num +=gain[i];
        if(max<num){
            max = num;
        }
        }
        return max;
    }
};