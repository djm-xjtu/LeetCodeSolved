class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int f[n+1][m+1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        int sum[n+1];
        sum[0] = 0;
        for(int i = 0; i < n; i++){
            sum[i+1] = sum[i] + nums[i];
        }
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= min(i,m); k++){
                for(int j = i; j >= k; j--){
                    f[i][k] = min(f[i][k], max(f[j-1][k-1], sum[i] - sum[j-1]));
                }
            }
        }
        return f[n][m];
    }
};