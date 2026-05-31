/*
APPROACH - 
in the problem it is given to us that if the mass of the planet is greater than or equal to the 
mass of the asteroid then in that case asteroid will get desetroyed and it's mass will get added 
to the mass of the planet and we will return true as the answer. But if the mass of the asteroid 
is greater than the mass of the planet then in that case planet will get destroyed and it will return
false.
we have been given integer mass and an array in which asteroids mass is there.
so first we will sort the mass of the astroids in ascending order and after that 
we will compare the mass of the planet from 0 index of array and if the the mass of
planet is smaller than the asteroid then we will return false else we will continue to 
traverse through rest of the array and keep on adding the mass of smaller asteroids to 
the mass of planet.
since here we are sorting the asteroid array then it means we are using greedy.

Time Complexity = O(n)
Space Complexity = O(1) 
*/

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