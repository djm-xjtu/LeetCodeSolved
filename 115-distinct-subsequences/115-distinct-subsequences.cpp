class Solution {
public:
    int numDistinct(string s, string t) {
        int sn = s.size(), tn = t.size();
        unsigned long long f[1010][1010];
        for(int i = 0; i <= sn; i++) f[i][0] = 1;
        for(int i = 1; i <= sn; i++){
            for(int j = 1; j <= tn; j++){
                f[i][j] = f[i-1][j];
                if(s[i-1] == t[j-1]){
                    f[i][j] += f[i-1][j-1];
                }
            }
        }
        return f[sn][tn];
    }
};