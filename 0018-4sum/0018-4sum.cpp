class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(1ll*nums[i]*4 > target) break;
            if(nums[i] + 1ll*nums.back()*3 < target) continue;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            
            for(int j = i + 1; j < n; j++){
                if(nums[i] + 1ll*nums[j]*3 > target) break;
                if(nums[i] + nums[j] + 1ll*nums.back()*2 < target) continue;
                if(j > i + 1 && nums[j-1] == nums[j]) continue;
                
                int x = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while(l < r){
                    if(nums[l] + nums[r] == x){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l < r && nums[l-1] == nums[l]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                    else if(nums[l] + nums[r] < x) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};