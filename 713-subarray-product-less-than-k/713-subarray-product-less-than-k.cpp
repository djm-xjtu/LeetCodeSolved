class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 1, l = 0, r = 0;
        if(k <= 1) return 0;
        while(r < n){
            sum *= nums[r];
            while(l < n && sum >= k) sum /= nums[l++];
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};