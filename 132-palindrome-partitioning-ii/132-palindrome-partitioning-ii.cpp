class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        bool dp[2010][2010]; //dp[i][j]表示i-j是不是回文串
        memset(dp, 0, sizeof dp);
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= j; i++){
                if(s[i] == s[j])
                    if(i + 1 > j - 1 || dp[i+1][j-1]) dp[i][j] = 1;
            }
        }

        vector<int> f(n+1, 100000);//f[i]表示到0～i的串都是分为回文串的数量，因此最后要-1
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= i; k++){
                if(dp[k][i]) f[i] = min(f[i], f[k-1] + 1);
            }
        }

        return f[n] - 1;
    }
};