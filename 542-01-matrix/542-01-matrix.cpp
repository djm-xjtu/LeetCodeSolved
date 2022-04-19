class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        vector<vector<int>> d(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0) q.push({i, j}), d[i][j] = 0;
            }
        }
        while(q.size()){
            auto t = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(d[nx][ny] != -1 || mat[nx][ny] == 0) continue;
                d[nx][ny] = d[t.first][t.second] + 1;
                q.push({nx, ny});
            }
        }
        return d;
    }
};