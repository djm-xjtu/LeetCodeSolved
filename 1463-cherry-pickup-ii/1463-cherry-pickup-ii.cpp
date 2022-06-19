class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int f[n][m][m], ans = -500;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int y = 0; y < m; y++)
                    f[i][j][y] = -500;
        f[0][0][m-1] = grid[0][0] + grid[0][m-1];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int y = 0; y < m; y++){
                    for(int k1 = -1; k1 <= 1; k1++){
                        for(int k2 = -1; k2 <= 1; k2++){
                            int l = j + k1, r = y + k2;
                            if(l < 0 || l >= m || r < 0 || r >= m) continue;
                            if(l == r) continue;
                            f[i][l][r] = max(f[i][l][r], f[i-1][j][y] + grid[i][l] + grid[i][r]);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, f[n-1][i][j]);
            }
        }
        return ans;
    }
};