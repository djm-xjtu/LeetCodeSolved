class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int f[n+1][n+1][n+1];
        memset(f, -50, sizeof f);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int x = 1; x <= n; x++){
                    int y = i + j - x;
                    if(y < 1 || y > n) continue;
                    if(grid[i-1][j-1] == -1 || grid[x-1][y-1] == -1) continue;
                    if(i == 1 && j == 1 && x == 1){
                        f[i][j][x] = grid[0][0];
                        continue;
                    }
                    f[i][j][x] = max(f[i][j][x], f[i-1][j][x-1]);
                    f[i][j][x] = max(f[i][j][x], f[i][j-1][x-1]);
                    f[i][j][x] = max(f[i][j][x], f[i-1][j][x]);
                    f[i][j][x] = max(f[i][j][x], f[i][j-1][x]);

                    if(i == x && j == y)
                        f[i][j][x] += grid[i-1][j-1];
                    else
                        f[i][j][x] += grid[i-1][j-1] + grid[x-1][y-1];
                }
            }
        }
        return max(0, f[n][n][n]);
    }
};