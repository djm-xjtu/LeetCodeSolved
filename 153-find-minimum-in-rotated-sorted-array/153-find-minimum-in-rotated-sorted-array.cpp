class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() >= nums[0]) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= nums[0]) l = mid + 1; // 因为要取到第一个绝对小于nums[0]的数
            else r = mid;
        }
        return nums[l];
    }
};