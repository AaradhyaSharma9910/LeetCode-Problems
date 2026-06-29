#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string &val: patterns){
            if(word.find(val) != string::npos){
                ans++;
            }
        }
        return ans;
    }
};