class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxP = nums[0], minP = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; i++){
            int t = maxP;
            // maxP = 0 and nums[i] > 0 => nums[i]
            // maxP < 0 and nums[i] < 0 || totally opposite => maxP * nums[i]
            // minP > 0 and nums[i] < 0 || totally opposite => minP * nums[i]
            maxP = max(max(maxP * nums[i], nums[i]), minP * nums[i]);
            minP = min(min(minP * nums[i], nums[i]), t * nums[i]);
            res = max(res, maxP);
        }
        return res;
    }
};