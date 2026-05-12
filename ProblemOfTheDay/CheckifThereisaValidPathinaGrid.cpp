#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        //direction vectors: up,down,left,right
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        //mapping type = allowed directions index
        vector<vector<int>> mp = {
            {},// dummy (0 index)
            {2,3},// 1 = left,right
            {0,1},// 2 = up,down
            {2,1},// 3 = left, down
            {3,1},// 4 = right, down
            {2,0},// 5 = left, up
            {3,0}// 6 = right, up
        };
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;
        while(!q.empty())
        {
            auto[i,j] = q.front();
            q.pop();
            if(i == m-1 && j == n-1) return true;
            int type = grid[i][j];
            for(int d:mp[type])
            {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if(ni<0 || nj<0 || ni>=m || nj>=n || vis[ni][nj])continue;
                int nextType = grid[ni][nj];
                //check reverse connection
                for(int back : mp[nextType]){
                    int bi = ni + dirs[back][0];
                    int bj = nj + dirs[back][1];
                    if(bi == i && bj == j){
                        vis[ni][nj] = true;
                        q.push({ni,nj});
                        break;
                    }
                }
            } 
        }
        return false;
    }
};