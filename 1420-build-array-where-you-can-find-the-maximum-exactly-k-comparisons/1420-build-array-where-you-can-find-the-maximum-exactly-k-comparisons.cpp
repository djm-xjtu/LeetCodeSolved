class Solution {
public:
    int numOfArrays(int n, int m, int K) {
        int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<vector<ll>>> f(n+1, vector<vector<ll>>(m+1, vector<ll>(K+1, 0)));
        //前i个数，前j个数，代价是k
        for(int i = 0; i <= m; i++) f[0][i][0] = 1ll*1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= K && k <= i; k++){
                    f[i][j][k] = (f[i][j-1][k] + f[i][j][k]) % mod;
                    f[i][j][k] = (f[i][j][k] + f[i-1][j-1][k-1]) % mod;
                    f[i][j][k] = (f[i][j][k] + (f[i-1][j][k] - f[i-1][j-1][k] + mod) * j) % mod;
                }
            }
        }
        return f[n][m][K];
    }
};