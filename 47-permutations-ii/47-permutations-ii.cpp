class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    bool vis[10];
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int u){
        if(u == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            if(i > 0 && nums[i-1] == nums[i] && !vis[i-1]) continue;
            vis[i] = 1;
            path.push_back(nums[i]);
            dfs(nums, u+1);
            path.pop_back();
            vis[i] = 0;
        }
    }
};