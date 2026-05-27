#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int count = 0;
        vector<int> firstUpper(26,-1),lastLower(26,-1);
        for(int i =0;i<n;i++){
            char c = word[i];
            if(islower(c)){
                lastLower[c-'a']=i;
            }else if(firstUpper[c-'A']==-1){
                firstUpper[c-'A']=i;
            }
        }
        for(int i = 0;i<26;i++){
            if(lastLower[i] !=-1 &&  firstUpper[i] !=-1 && lastLower[i]<firstUpper[i]){
                count++;
            }
        }
        return count;
    }
};