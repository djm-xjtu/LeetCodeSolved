class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n+1], g[n+1];
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        
        for(int i = 1; i <= n; i++){
            f[i] = max(f[i-1], g[i-1]);
            g[i] = f[i-1] + nums[i-1]; // 因为nums下标从0开始，而f、g是从1开始
        }
        
        return max(f[n], g[n]);
    }
};