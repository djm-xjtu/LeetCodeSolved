class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int dp[n+1][m+1];
        int s[n+1];
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            s[i] = s[i-1] + nums[i-1];
        }
        memset(dp, 0x3f3f3f3f, sizeof dp);
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= min(m, i); j++){
                for(int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], s[i] - s[k]));
                }
            }
        }
        
        return dp[n][m];
    }
};