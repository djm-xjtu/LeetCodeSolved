class Solution {
public:
    int ans;
    vector<bool> row, col, diag, anti_diag;
    int totalNQueens(int n) {
        row = col = vector<bool>(n, 0);
        diag = anti_diag = vector<bool>(2 * n, 0);
        dfs(0,0,0,n);
        return ans;
    }
    
    void dfs(int x, int y, int s, int n){
        if(y == n) x ++, y = 0;
        if(x == n){
            if(s == n) ans++;
            return;
        }
        
        dfs(x, y+1, s, n);
        
        if(!row[x] && !col[y] && !diag[x + y] && !anti_diag[n - 1 - x + y]){
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = 1;
            
            dfs(x, y+1, s+1, n);
            
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = 0;
        }
    }
};