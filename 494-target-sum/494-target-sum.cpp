class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // sum(p) - sum(n) = target
        // 2*sum(p) = target + sum
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((target + sum) % 2 || target + sum < 0) return 0;
        int n = nums.size();
        int f[(target + sum) / 2 + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = (target + sum) / 2; j >= nums[i]; j--){
                f[j] += f[j - nums[i]];
            }
        }
        return f[(target + sum) / 2];
    }
};