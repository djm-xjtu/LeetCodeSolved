class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        K = min(K, n/2);
        int dp[n][2][K+1];
        memset(dp, 0, sizeof dp);// To make it easy, write it every time
        for(int k = 0; k <= K; k++){
            dp[0][0][k] = 0;
            dp[0][1][k] = -prices[0];
        }
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= K; k++){
                dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k] + prices[i]);
                dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k-1] - prices[i]);
            }
        }
        return dp[n-1][0][K];
    }
};