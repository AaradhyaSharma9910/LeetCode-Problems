#include<bits/stdc++.h>
using namespace std;
 class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        vector<int> window(128,0);
        // Step 1: fill need
        for(char c : t)
        need[c]++;

        int required = 0;
        for(int i=0;i<128;i++)
        {
            if(need[i]>0)
            required++;
        }
        int left = 0, right = 0;
        int formed = 0;
        int minLen = INT_MAX, start = 0;
        while (right < s.size())
        {
            char c = s[right];
            window[c]++;

            //if freq matches 
            if(need[c] > 0 && window[c]==need[c])
            {
                formed++;
            }
            // shrink window
            while (left<= right && formed == required){
               if(right - left + 1 < minLen)
               {
                minLen = right -left + 1;
                start = left;
            }
            char ch = s[left];
            window[ch]--;
            if(need[ch] > 0 && window[ch] < need[ch])
            {
                formed--;
            }
            left++;
        }
        right++;
       
    }
      return minLen == INT_MAX ? "" : s.substr(start,minLen);
}
};