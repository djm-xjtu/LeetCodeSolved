class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // first is lower[0], I assume that nums[i] is higher[i] and nums[i] is qualified, then we use two index to traverse the array
        // to search, if we get wrong, we assume i+1 is higher[i] and search and so on...
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) continue;
            int d = nums[i] - nums[0];
            if(d == 0 || d & 1 > 0) continue;
            int k = d / 2;
            vector<bool> vis(n);
            vis[i] = true;
            vector<int> ans{(nums[0] + nums[i]) / 2};
            int l = 1, r = i + 1;
            while(r < n){
                while(l < n && vis[l]) l++;
                while(r < n && nums[r] - nums[l] < 2 * k) r++;
                if(r == n || nums[r] - nums[l] > 2 * k) break;
                vis[r] = true;
                ans.push_back((nums[l] + nums[r]) / 2);
                l++, r++;
            }
            if(ans.size() == n / 2) return ans;
        }
        return {};
    }
};