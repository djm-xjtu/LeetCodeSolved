class Solution {
public:
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    bool vis[60][60];
    int n, m;
    int dfs(int sx, int sy){
        if(sx < 0 || sx >= n || sy < 0 || sy >= m || g[sx][sy] == 0 || vis[sx][sy] == 1) return 0;
        int cnt = 1;
        vis[sx][sy] = 1;
        for(int i = 0; i < 4; i++){
            cnt += dfs(sx + dx[i], sy + dy[i]);
        }
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) res = max(res,dfs(i, j));
            }
        }
        return res;
    }
};