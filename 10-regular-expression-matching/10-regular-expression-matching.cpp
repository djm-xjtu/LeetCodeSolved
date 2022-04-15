class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = " " + s;
        p = " " + p;
        bool f[n+1][m+1];
        memset(f, false, sizeof f);
        f[0][0] = 1;
        //如何去理解这个状态转移？
        //比如f[i][j] = f[i][j] | f[i-1][j]
        //f[i][j]在前面可能已经匹配成功，因此不能把前面的结果吞了
        //这里是i和*匹配了，所以只需要考虑i-1和j是否匹配即可，如果是true，i和j就匹配上了，因为j可以匹配多个，所以不用j-1
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i > 0 && (s[i] == p[j] || p[j] == '.')){
                    f[i][j] = f[i-1][j-1];
                }
                if(p[j] == '*'){
                    if(j >= 2){
                        f[i][j] = f[i][j] | f[i][j-2];
                    }
                    if(i > 0 && (s[i] == p[j-1] || p[j-1] == '.')){
                        f[i][j] = f[i][j] | f[i-1][j];
                    }
                }
            }
        }
        return f[n][m];
    }
};