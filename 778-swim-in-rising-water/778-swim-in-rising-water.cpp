typedef pair<int, int> PII;
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int n;
    bool vis[60][60];
    bool bfs(vector<vector<int>>& grid, int x, int y, int time){
        queue<PII> q;
        q.push({x, y});
        while(q.size()){
            auto t = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(vis[nx][ny] == 1 || grid[nx][ny] > time) continue;
                if(nx == n - 1 && ny == n - 1) return true;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 1) return 0;
        int l = 0, r = 2500;
        while(l < r){
            int mid = l + r >> 1;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++) vis[i][j] = 0;
            }
            if(grid[0][0] <= mid && bfs(grid, 0, 0, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};