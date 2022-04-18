class Solution {
public:
    vector<vector<int>> g;
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int d[60][60];
    int shortestDistance(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        int point = 0;
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 1){
                    ans = 1e9;
                    int step = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(q.size()){
                        step++;
                        int len = q.size();
                        while(len--){
                            auto t = q.front(); q.pop();
                            for(int i = 0; i < 4; i++){
                                for(int j = 0; j < 4; j++){
                                    int nx = t.first + dx[i], ny = t.second + dy[i];
                                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                    if(g[nx][ny] == point){
                                        g[nx][ny]--;
                                        q.push({nx, ny});
                                        d[nx][ny] += step;
                                        ans = min(ans, d[nx][ny]);
                                    }
                                }
                            }
                        }
                    }
                    point--;
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};