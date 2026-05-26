#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> upper,lower;
        for(char c:word){
            if(islower(c)){
                lower.set(c-'a');

            }
            else{
                upper.set(c-'A');
            }
        }
        lower = lower&upper;
        return lower.count();
    }
};