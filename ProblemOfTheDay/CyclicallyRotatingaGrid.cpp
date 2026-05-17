#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> elems;
            vector<pair<int,int>> pos;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for(int j = left; j <= right; j++) {
                elems.push_back(grid[top][j]);
                pos.push_back({top, j});
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                elems.push_back(grid[i][right]);
                pos.push_back({i, right});
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                elems.push_back(grid[bottom][j]);
                pos.push_back({bottom, j});
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                elems.push_back(grid[i][left]);
                pos.push_back({i, left});
            }

            int len = elems.size();

            int rot = k % len;

            vector<int> rotated(len);

            // counter-clockwise rotation
            for(int i = 0; i < len; i++) {
                rotated[(i + len - rot) % len] = elems[i];
            }

            // place back
            for(int i = 0; i < len; i++) {

                auto [x, y] = pos[i];

                grid[x][y] = rotated[i];
            }
        }

        return grid;
    }
};