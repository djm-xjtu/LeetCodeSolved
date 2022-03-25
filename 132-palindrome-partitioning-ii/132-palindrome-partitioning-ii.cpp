class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= j; i++){
                if(s[i] == s[j])
                    if(i + 1 > j - 1 || dp[i+1][j-1]) dp[i][j] = 1;
            }
        }

        vector<int> f(n + 1, 10000);
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= i; k++){
                if(dp[k][i]) f[i] = min(f[i], f[k-1] + 1);
            }
        }

        return f[n] - 1;
    }
};