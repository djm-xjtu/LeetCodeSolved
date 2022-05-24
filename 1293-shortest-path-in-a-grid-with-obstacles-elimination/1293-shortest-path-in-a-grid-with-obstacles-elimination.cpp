class Solution {
public:
    //记录3个状态的BFS
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int shortestPath(vector<vector<int>>& g, int k) {
        n = g.size(), m = g[0].size();
        if(k >= n + m - 2) return n + m - 2;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k + 1, 0)));
        int step = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, k);
        while(q.size()){
            int len = q.size();
            step++;
            while(len--){
                auto [x, y, d] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny][d]) continue;
                    if(nx == n - 1 && ny == m - 1){
                        if(g[nx][ny] == 1 && d > 0) return step;
                        if(g[nx][ny] == 0) return step;
                    }
                    if(g[nx][ny] == 1){
                        if(d > 0) vis[nx][ny][d] = 1, q.emplace(nx, ny, d - 1);
                    }
                    else{
                        vis[nx][ny][d] = 1;
                        q.emplace(nx, ny, d);
                    }
                }
            }
        }
        return -1;
    }
};