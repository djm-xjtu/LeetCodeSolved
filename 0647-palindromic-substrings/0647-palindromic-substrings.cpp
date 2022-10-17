class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        int f[n][n];
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++){
            f[i][i] = 1;
            cnt++;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i == 1 || f[i+1][j-1] == 1){
                        cnt++;
                        f[i][j] = 1;
                    }
                }
            }
        }
        return cnt;
    }
};