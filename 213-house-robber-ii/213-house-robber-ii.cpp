class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int f1[n+1], f2[n+1], g1[n+1], g2[n+1];
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        memset(g1, 0, sizeof g1);
        memset(g2, 0, sizeof g2);
        
        for(int i = 1; i < n; i++){
            f1[i] = max(f1[i-1], g1[i-1]);
            g1[i] = f1[i-1] + nums[i-1];
        }
        
        for(int i = 2; i <= n; i++){
            f2[i] = max(f2[i-1], g2[i-1]);
            g2[i] = f2[i-1] + nums[i-1];
        }
        
        return max(max(f1[n-1],g1[n-1]), max(f2[n], g2[n]));
    }
};