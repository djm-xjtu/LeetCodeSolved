class Solution {
public:
    vector<vector<int>> g;
    int f[210][210];
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int solve(int sx, int sy){
        if(f[sx][sy] != -1) return f[sx][sy];
        f[sx][sy] = 1;
        for(int i = 0; i < 4; i++){
            int nx = sx + dx[i], ny = sy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] > g[sx][sy]){
                f[sx][sy] = max(f[sx][sy], solve(nx, ny) + 1);
            }
        }
        return f[sx][sy];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        g = matrix;
        n = g.size(), m = g[0].size();
        int ans = 0;
        memset(f, -1, sizeof f);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, solve(i, j));
            }
        }
        return ans;
    }
};