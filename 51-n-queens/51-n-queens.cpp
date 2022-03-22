class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> row, col, diag, anti_diag;
    vector<vector<string>> solveNQueens(int n) {
        row = col = vector<bool>(n, 0);
        diag = anti_diag = vector<bool>(2 * n, 0);
        path = vector<string>(n, string(n,'.'));
        dfs(0, 0, 0, n);
        return ans;
    }
    
    void dfs(int x, int y, int s, int n){
        if(y == n) x ++, y = 0;
        if(x == n){
            if(s == n){
                ans.push_back(path);
            }
            return;
        }
        
        dfs(x, y+1, s, n);
        
        if(!row[x] && !col[y] && !diag[x + y] && ! anti_diag[n - 1 - x + y]){
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = 1;
            path[x][y] = 'Q';
            
            dfs(x, y+1, s+1, n);
            
            path[x][y] = '.';
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = 0;
        }
    }
};