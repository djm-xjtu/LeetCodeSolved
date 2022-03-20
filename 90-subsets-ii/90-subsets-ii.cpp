class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int u){
        ans.push_back(path);
        for(int i = u; i < n; i++){
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
            while(i + 1 < n && nums[i] == nums[i+1]) ++i;
        }
    }
};