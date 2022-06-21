class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto st : nums){
            sum += st;
        }
        if(sum % 2) return false;
        sum /= 2;
        bool f[sum+1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= nums[i]; j--){
                f[j] = f[j] || f[j - nums[i]];
            }
        }
        return f[sum];
    }
};