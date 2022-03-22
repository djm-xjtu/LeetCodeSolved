class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return ans;
    }
    void dfs(vector<int>& candidates, int i, int sum, int target){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        if(i == candidates.size() || sum > target) return;
        dfs(candidates, i+1, sum, target);
        path.push_back(candidates[i]);
        dfs(candidates, i, sum+candidates[i], target);
        path.pop_back();
    }
};