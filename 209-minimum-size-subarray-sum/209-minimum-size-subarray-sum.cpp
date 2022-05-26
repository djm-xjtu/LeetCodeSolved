class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0, ans = INT_MAX;
        while(l < n){
            while(r < n && sum < target) sum += nums[r++];
            if(sum < target) break;
            ans = min(ans, r - l);
            sum -= nums[l++];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};