class Solution {
public:
    bool f[210][210];
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1 + n2 != n3) return 0;
        f[0][0] = 1;
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                if(i > 0) f[i][j] |= (f[i-1][j] && s1[i - 1] == s3[i + j - 1]);
                if(j > 0) f[i][j] |= (f[i][j-1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return f[n1][n2];
    }
};