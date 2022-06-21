class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 1e9 + 7;
        long long f[n][m], g[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                f[i][j] = INT_MIN;
                g[i][j] = INT_MIN;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    f[i][j] = grid[i][j];
                    g[i][j] = grid[i][j];
                    continue;
                }
                if(i > 0 && j > 0){
                    f[i][j] = max(max(f[i][j-1] * grid[i][j], f[i-1][j] * grid[i][j]), 
                                max(g[i][j-1] * grid[i][j], g[i-1][j] * grid[i][j]));
                    g[i][j] = min(min(f[i][j-1] * grid[i][j], f[i-1][j] * grid[i][j]), 
                                min(g[i][j-1] * grid[i][j], g[i-1][j] * grid[i][j]));
                }
                else if(i > 0){
                    f[i][j] = max(f[i-1][j] * grid[i][j], g[i-1][j] * grid[i][j]);
                    g[i][j] = min(f[i-1][j] * grid[i][j], g[i-1][j] * grid[i][j]);
                }
                else if(j > 0){
                    f[i][j] = max(f[i][j-1] * grid[i][j], g[i][j-1] * grid[i][j]);
                    g[i][j] = min(f[i][j-1] * grid[i][j], g[i][j-1] * grid[i][j]);
                }
            }
        }
        return f[n-1][m-1] < 0 ? -1 : f[n-1][m-1] % mod;
    }
};