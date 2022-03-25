class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> g(n+1, vector<bool>(n+1,0));
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= j; i++){
                if(s[i] == s[j]){
                    if(i + 1 > j - 1 || g[i+1][j-1]) g[i][j] = 1;
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(g[1][i] && g[i+1][j] && g[j+1][n]) return 1;
            }
        }
        return 0;
    }
};