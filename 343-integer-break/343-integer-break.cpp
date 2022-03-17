class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        for(int i = 2; i <= n; i++){
            int max_cur = 0;
            for(int j = 1; j < i; j++){
                max_cur = max(max_cur, max(j*(i-j), j*dp[i-j]));
            }
            dp[i] = max_cur;
        }
        return dp[n];
    }
};