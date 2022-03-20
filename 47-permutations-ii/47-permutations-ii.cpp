class Solution {
public:
    bool vis[10];
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int index, int start){
        if(index == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if(vis[i]) continue;
            vis[i] = 1;
            path[i] = nums[index];
            if(index + 1 < nums.size() && nums[index+1] != nums[index]) dfs(nums, index+1, 0);
            else dfs(nums, index+1, i+1);
            vis[i] = 0;
        }
    }
};