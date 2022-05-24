class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == ')') return false;
        vector<vector<vector<bool>>> f;
        for (int i = 0; i < n; i++) {
            f.push_back(vector<vector<bool>>());
            for (int j = 0; j < m; j++) f.back().push_back(vector<bool>(n + m));
        }
        f[0][0][1] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                int t = (grid[i][j] == '(' ? 1 : -1);
                for(int k = 0; k < n + m; k++){
                    int pre = k - t;
                    if(pre < 0 || pre >= n + m) continue;
                    if(i > 0) f[i][j][k] = f[i][j][k] || f[i-1][j][pre];
                    if(j > 0) f[i][j][k] = f[i][j][k] || f[i][j-1][pre];
                }
            }
        }
        return f[n-1][m-1][0];
    }
};