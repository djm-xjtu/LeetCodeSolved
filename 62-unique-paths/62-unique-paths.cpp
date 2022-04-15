class Solution {
public:
    int uniquePaths(int n, int m) {
        long long f[n+1][m+1];
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) f[i][0] = 1;
        for(int i = 0; i < m; i++) f[0][i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[n-1][m-1];
    }
};