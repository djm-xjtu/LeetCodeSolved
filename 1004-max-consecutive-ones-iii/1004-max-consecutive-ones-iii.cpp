class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), sum = 0;
        for(int l = 0, r = 0; r < n; r++){
            sum += nums[r] == 0 ? 1 : 0;
            while(sum > k){
                sum -= nums[l] == 0 ? 1 : 0;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};