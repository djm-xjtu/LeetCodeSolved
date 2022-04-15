class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = " " + s;
        p = " " + p;
        bool f[n+1][m+1];
        memset(f, false, sizeof f);
        f[0][0] = 1;
        // s没有数字也可能和p匹配，因为*可以匹配0或2个及以上个
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //枚举s非空位置和p匹配
                if(i > 0 && (s[i] == p[j] || p[j] == '.')){
                    f[i][j] = f[i][j] | f[i-1][j-1];
                }
                //这时候s的空位置可以和p匹配
                if(p[j] == '*'){
                    if(j >= 2){
                        // bssc
                        // bb*
                        f[i][j] = f[i][j] | f[i][j-2];//表示匹配0个前面的数，因此只需要j-2和i匹配即可
                    }
                    if(i > 0 && (s[i] == p[j-1] || p[j-1] == '.')){
                        f[i][j] = f[i][j] | f[i-1][j];//表示i可以匹配j的位置，所以只需要i-1和j匹配
                    }
                }
            }
        }
        return f[n][m];
    }
};