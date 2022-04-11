class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int f[20][20];
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) f[i][i] = nums[i];
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                f[i][j] = max(-f[i+1][j] + nums[i], -f[i][j-1] + nums[j]);
            }
        }
        return f[0][n-1] >= 0;
    }
};