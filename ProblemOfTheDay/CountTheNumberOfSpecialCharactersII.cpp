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
/*
Theory:
We store:
1. Last occurrence index of every lowercase letter.
2. First occurrence index of every uppercase letter.

A character is considered special if:
- Both lowercase and uppercase versions exist.
- The lowercase letter appears before the uppercase letter.

Example:
"aA" -> special
"Aa" -> not special

Time Complexity:
O(n + 26)
- O(n) for traversing the string
- O(26) for checking all alphabets

Overall TC: O(n)

Space Complexity:
O(26 + 26)

Overall SC: O(1)
since alphabet size is constant.
*/