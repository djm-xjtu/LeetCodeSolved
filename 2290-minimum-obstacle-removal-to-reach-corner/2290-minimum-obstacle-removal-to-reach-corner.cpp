class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        // 0-1BFS模版题 双端队列广搜
        deque<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        q.emplace_back(0, 0);
        d[0][0] = 0;
        while(q.size()){
            auto [x, y] = q.front();
            q.pop_front();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || d[nx][ny] != INT_MAX) continue;
                d[nx][ny] = d[x][y] + grid[nx][ny];
                if(grid[nx][ny])
                    q.emplace_back(nx, ny);
                else
                    q.emplace_front(nx, ny);
            }
        }
        return d[n-1][m-1];
    }
};