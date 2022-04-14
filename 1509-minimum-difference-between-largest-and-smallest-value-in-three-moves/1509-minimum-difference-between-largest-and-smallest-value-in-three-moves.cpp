class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        // a1 a2 a3 a4 a5 a6 a7 
        // +0, -3; +1, -2; +2, -1; +3, -0    
        int ans = 2e9;
        for(int i = 0; i <= 3; i++){
            ans = min(ans, nums[n-1-i] - nums[3-i]);
        }
        return ans;
    }
};