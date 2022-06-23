class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int cnt) {
        int n = nums.size();
        double f[n+1][cnt+1];
        memset(f, 0, sizeof f);
        //注意这里设置不可达边界为不可能转移
        for(int i = 1; i <= n; i++){
            f[i][0] = INT_MIN;
        }
        int sum[n+1];
        sum[0] = 0;
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + nums[i];
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= min(i, cnt); k++){
                for(int j = i; j >= k; j--){
                    f[i][k] = max(f[i][k], f[j-1][k-1] + (sum[i] - sum[j-1])*1.0/(i - j + 1));
                }
            }
        }
        double ans = 0;
        for(int i = 1; i <= cnt; i++){
            ans = max(ans, f[n][i]);
        }
        return ans;
    }
};