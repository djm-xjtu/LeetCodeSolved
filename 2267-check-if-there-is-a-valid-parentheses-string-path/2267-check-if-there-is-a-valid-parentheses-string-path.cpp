class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[2] = {0, 1}, dy[2] = {1, 0};
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(n + m, 0)));
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 1);
        vis[0][0][0] = 1;
        while(q.size()){
            auto [x, y, d] = q.front();
            q.pop();
            for(int i = 0; i < 2; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny][d]) continue;
                //不要修改状态d，在加入队列时修改，不然会影响其他方向
                int t = (grid[nx][ny] == '(' ? 1 : -1);
                if(nx == n - 1 && ny == m - 1 && d + t == 0) return true;
                if(d + t >= 0) q.emplace(nx, ny, d + t), vis[nx][ny][d] = true;
            }
        }
        return false;
    }
};