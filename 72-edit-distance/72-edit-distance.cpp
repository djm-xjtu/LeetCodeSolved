class Solution {
public:
    int dp[600][600];
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(!n || !m) return n + m;
        
        for(int i = 1; i <= n; i++) dp[i][0] = i;
        for(int i = 1; i <= m; i++) dp[0][i] = i;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = dp[i-1][j-1];
                dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
            }
        }
        
        return dp[n][m];
        
    }
};