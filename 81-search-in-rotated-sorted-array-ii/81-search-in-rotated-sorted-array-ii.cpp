class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if(n == 1) return target == nums[0];
        while(l < r && nums[0] == nums[r]) r--;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        if(target >= nums[0]){
            l = 0;
        }
        else{
            l = l + 1, r = n - 1;
        }
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1; 
        }
        if(l < n && nums[l] == target) return true;
        return false;
    }
};