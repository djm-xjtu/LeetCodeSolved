class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    bool vis[10][10];
    bool dfs(vector<vector<char>>& board, string word, int x, int y, string s, int idx){
        if(s == word) return 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || vis[nx][ny]) continue;
            if(word[idx] == board[nx][ny]){
                vis[nx][ny] = 1;
                if(dfs(board, word, nx, ny, s + word[idx], idx+1)) return 1;
                vis[nx][ny] = 0;
            }
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    string s = "";
                    s += word[0];
                    vis[i][j] = 1;
                    if(dfs(board, word, i, j, s, 1)) return 1;
                    vis[i][j] = 0;
                }
            }
        }
        return 0;
    }
};