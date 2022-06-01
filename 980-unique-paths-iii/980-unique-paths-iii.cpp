class Solution {
public:
    int n, m;
    int dfs(vector<vector<int>>& grid, int x, int y, int cnt){
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) return 0;
        if(grid[x][y] == 2) return cnt == 0 ? 1 : 0;
        grid[x][y] = -1;
        int sum = 0;
        sum += dfs(grid,x-1,y,cnt-1) + dfs(grid,x+1,y,cnt-1) + dfs(grid,x,y-1,cnt-1) + dfs(grid,x,y+1,cnt-1);
        grid[x][y] = 0;
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 1, r = 0, c = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) r = i, c = j;
                if(grid[i][j] == 0) cnt++;
            }
        }
        return dfs(grid, r, c, cnt);
    }
};