class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, res = 0;
        while(l < r){
            res += nums[r] - nums[l];
            l++, r--;
        }
        return res;
    }
};