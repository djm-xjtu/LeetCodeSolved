class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int dp[n+2][n+2]; // dp[i][j]戳爆序号为i～j气球的最大金币量
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i < n - 1; i++){
            dp[i][i] = nums[i] * nums[i];
        }
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;
                for(int k = i; k <= j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j]);
                }
            }
        }
        
        return dp[1][n];
    }
};