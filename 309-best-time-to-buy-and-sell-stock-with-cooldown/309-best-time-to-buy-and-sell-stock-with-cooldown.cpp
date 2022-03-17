class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][3];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][1] + prices[i]; // sell and frezen
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]); // buy
            dp[i][2] = max(dp[i-1][2], dp[i-1][0]); // unfrezen
        }
        return max(dp[n-1][0], dp[n-1][2]); // max(sell and frezen or unfrezen)
    }
};