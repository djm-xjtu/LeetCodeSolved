class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        if(n > m) return 0;
        int f[n+1][m+1];
        memset(f, 0, sizeof f);
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                if(s[i] == t[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
                res = max(res, f[i][j]);
            }
        }
        if(res == n) return 1;
        return 0;
    }
};