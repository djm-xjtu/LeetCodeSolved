class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 1));

        dp[0][1] = dp[0][0] = 1;
        for (int i = 1; i<n; i++){
            if(nums[i] == nums[i-1])
                dp[i][1] = dp[i-1][1], dp[i][0] = dp[i-1][0];
            else if (nums[i] > nums[i-1])
                dp[i][1] = dp[i-1][0] + 1, dp[i][0] = dp[i-1][0];   
            else if (nums[i] < nums[i-1])
                dp[i][0] = dp[i-1][1] + 1, dp[i][1] = dp[i-1][1];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};