class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size(), dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        queue<tuple<int, int, int>> q;
        q.emplace(start[0], start[1], 0);
        grid[start[0]][start[1]] = -grid[start[0]][start[1]];
        vector<tuple<int, int, int, int>> path;
        while(q.size()){
            auto[x, y, d] = q.front(); q.pop();
            if(-grid[x][y] >= pricing[0] && -grid[x][y] <= pricing[1])
                path.push_back({d, -grid[x][y], x, y});
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(grid[nx][ny] <= 0) continue;
                grid[nx][ny] = -grid[nx][ny];
                q.emplace(nx, ny, d + 1);
            }
        }
        sort(path.begin(), path.end());
        vector<vector<int>> res;
        for(int i = 0; i < path.size() && i < k; i++){
            auto[a, b, x, y] = path[i];
            res.push_back({x, y});
        }
        return res;
    }
};