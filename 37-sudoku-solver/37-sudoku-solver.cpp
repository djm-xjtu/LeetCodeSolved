class Solution {
public:
    bool row[9][9], col[9][9], st[3][3][9];
    vector<vector<char>> ans;
    int n;
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = st[i / 3][j / 3][t] = 1;
                }
            }
        }
        dfs(board, 0, 0);
        
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y){
        if(y == n) x++, y = 0;
        if(x == n) {
            
            return 1;
        }
        
        if(board[x][y] != '.') return dfs(board, x, y + 1);
        
        for(int i = 0; i < 9; i++){
            if(!row[x][i] && !col[y][i] && !st[x/3][y/3][i]){
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = st[x/3][y/3][i] = 1;
                if(dfs(board, x, y+1)) return 1;
                row[x][i] = col[y][i] = st[x/3][y/3][i] = 0;
            }
        }
        
        board[x][y] = '.';
        return 0;
    }
};