class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool vis[2010][2010];
        memset(vis, 0, sizeof vis);
        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j; i++){
                if(s[i] == s[j])
                    if(i+1 > j-1 || vis[i+1][j-1]) vis[i][j] = 1;
            }
        }
        vector<int> f(n+1, 100000);
        f[0] = 0;
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= j; i++){
                if(vis[i-1][j-1]) f[j] = min(f[j], f[i-1] + 1);
            }
        }
        return f[n] - 1;
    }
};