class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() >= nums[0]) return nums[0];
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= nums[0]){
                l = mid + 1;
            }
            else r = mid;
        }
        return nums[l];
    }
};