#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // up, down, left, right
        vector<vector<int>> dirs = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        // allowed directions for each street type
        vector<vector<int>> mp = {
            {},
            {2,3}, // type 1 -> left,right
            {0,1}, // type 2 -> up,down
            {2,1}, // type 3 -> left,down
            {3,1}, // type 4 -> right,down
            {2,0}, // type 5 -> left,up
            {3,0}  // type 6 -> right,up
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            if(i == m-1 && j == n-1)
                return true;

            int type = grid[i][j];

            // all possible directions from current cell
            for(int d : mp[type])
            {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                // boundary + visited check
                if(ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj])
                    continue;

                int nextType = grid[ni][nj];

                // check whether next cell connects back
                for(int back : mp[nextType])
                {
                    int bi = ni + dirs[back][0];
                    int bj = nj + dirs[back][1];

                    if(bi == i && bj == j)
                    {
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