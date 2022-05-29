class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        vector<vector<int>> g(n + 1, vector<int>(2, 0));
        for(int i = 1; i <= n - 1; i++){
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + nums[i-1];
        }
        int ans = max(f[n-1][0], f[n-1][1]);
        for(int i = 2; i <= n; i++){
            g[i][0] = max(g[i-1][0], g[i-1][1]);
            g[i][1] = g[i-1][0] + nums[i-1];
        }
        ans = max(ans, max(g[n][0], g[n][1]));
        return ans;
    }
};