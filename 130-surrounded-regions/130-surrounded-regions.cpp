class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    
    void bfs(vector<vector<char>>& board, int x, int y){
        vector<pair<int, int>> res;
        bool vis[210][210];
        memset(vis, 0, sizeof vis);
        queue<pair<int, int>> q;
        q.push({x, y});
        res.push_back({x, y});
        vis[x][y] = 1;
        bool f = 0;
        while(q.size()){
            auto t = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) {
                    f = 1;
                    break;
                }
                if(!vis[nx][ny] && board[nx][ny] == 'O'){
                    q.push({nx, ny});
                    res.push_back({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            if(f) break;
        }
        if(!f){
            for(auto t : res){
                board[t.first][t.second] = 'X';
            }
        }
    }
    // OXXOX  OXXOX
    // XOOXO  XXXXO
    // XOXOX  XXXOX
    // OXOOO  OXOOO
    // XXOXO  XXOXO
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    bfs(board, i, j);
                }
            }
        }
        return;
    }
};