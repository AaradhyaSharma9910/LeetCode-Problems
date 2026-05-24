#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> dp;
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.resize(n,0);
        int maxi = 0;
        for(int i = 0; i < n ; i++){
             
             maxi = max(maxi,countMaxJump(arr,i,d));
        }
        return maxi;
    }
        int countMaxJump(vector<int>& arr, int index, int d){
            if (dp[index]!=0)
            return dp[index];
            int result = 1;
            //left side
            for(int j = index - 1; j >= max(index - d,0) && arr[index]>arr[j]; j--){

                result = max(result, 1 + countMaxJump(arr,j,d));
            }
                //right side
                  for(int j = index + 1; j <= min(index + d, (int)arr.size()- 1) && arr[index]>arr[j]; j++){
                result = max(result, 1 + countMaxJump(arr,j,d));


            }
            return dp[index] = result;
        }
        };        
        
    
