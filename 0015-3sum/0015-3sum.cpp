class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(3*nums[i] > 0) break;
            if(nums[i] + 2*nums.back() < 0) continue;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int x = -nums[i];
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[l] + nums[r] == x){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l-1] == nums[l]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }
                else if(nums[l] + nums[r] < x) l++;
                else r--;
            }
        }
        return ans;
    }
};