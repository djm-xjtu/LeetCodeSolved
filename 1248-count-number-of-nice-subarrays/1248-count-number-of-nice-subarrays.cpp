class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> f(50000, 0);
        int ans = 0, sum = 0;
        f[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1) sum ++;
            if(sum - k >= 0) ans += f[sum - k];
            f[sum]++;
        }
        return ans;
    }
};