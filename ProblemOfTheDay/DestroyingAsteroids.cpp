#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));
        for(int &m : asteroids){
            if(mass < m){
                return false;
            }else if (mass >=1e5){
                return true;
            }
            mass +=m;
        }
        return true;
    }
};