class Solution {
public:
    vector<vector<char>> g;
    int n, m;
    int ans;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    bool vis[310][310];
    bool dfs(int sx, int sy){
        if(sx < 0 || sx >= n || sy < 0 || sy >= m || g[sx][sy] == '0' || vis[sx][sy]) return 0;
        vis[sx][sy] = 1;
        for(int i = 0; i < 4; i++){
            dfs(sx + dx[i], sy + dy[i]);
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '1' && dfs(i, j)) res++;
            }
        }
        return res;
    }
};