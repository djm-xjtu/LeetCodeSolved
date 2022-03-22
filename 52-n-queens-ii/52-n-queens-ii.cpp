class Solution {
public:
    int ans;
    int totalNQueens(int n) {
        dfs(0,0,0,0,n);
        return ans;
    }
    
    void dfs(int row, int col, int ld, int rd, int n){
        if(row == n){
            ans++;
            return;
        }
        
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while(bits > 0){
            int pick = bits & -bits;
            dfs(row+1, col | pick, (ld | pick) << 1, (rd | pick) >> 1, n);
            bits &= (bits - 1);
        }
    }
};