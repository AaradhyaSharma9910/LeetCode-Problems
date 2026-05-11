#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int m,n;
vector<vector<bool>> visited;
vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid){
    visited[r][c] = true;
    for(auto &dir : directions){
        int nr = r + dir[0];
        int nc = c + dir[1];
        if(nr<0 || nc<0||nr>=m||nc>=n)
        continue;
        if(grid[nr][nc] != grid[r][c])
        continue;
        if(nr == pr && nc == pc)
        continue;
        if(visited[nr][nc])
        return true;
        if(dfs(nr,nc,r,c,grid))
        return true;
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid))
                    return true;
                }
            }
        }
        return false;
    }
};