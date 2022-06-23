class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool vis[n][n];
        memset(vis, 0, sizeof vis);
        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(i + 1 >= j - 1)
                        vis[i][j] = 1;
                    else
                        vis[i][j] = vis[i+1][j-1];
                }
            }
        }
        vector<int> f(n, INT_MAX/2);
        f[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(vis[j][i]){
                    if(j == 0)
                        f[i] = 1;
                    else
                        f[i] = min(f[i], f[j-1] + 1);
                }
            }
        }
        return f[n-1] - 1;
    }
};