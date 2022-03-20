class Solution {
public:
    bool vis[10];
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;
            vis[i] = 1;
            path.push_back(nums[i]);
            dfs(nums, index+1);
            path.pop_back();
            vis[i] = 0;
        }
    }
};