class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, path, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int i, int sum, int target, vector<int>& path, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        
        if(i == candidates.size() || sum > target) return;
        for(int j = i + 1; j < candidates.size(); j++){
            if(candidates[i] != candidates[j]){
                dfs(candidates, j, sum, target, path, ans);
                break;
            }
        }
        
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, sum + candidates[i], target, path, ans);
        path.pop_back();
    }
};