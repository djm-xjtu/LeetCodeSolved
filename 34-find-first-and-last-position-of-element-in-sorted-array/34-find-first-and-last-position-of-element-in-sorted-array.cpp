class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int start = 0, end = 0;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] < target) l = mid + 1; // 找第一个大于等于
            else r = mid;
        }
        if(nums[l] != target) return {-1,-1};
        start = l;
        
        l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] <= target) l = mid + 1; //找第一个大于
            else r = mid;
        }
        if(nums[l] > target) end = l - 1;
        else end = l;
        
        return {start, end};
    }
};