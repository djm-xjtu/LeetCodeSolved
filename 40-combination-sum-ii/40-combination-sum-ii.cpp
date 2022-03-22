class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        return ans;
    }
    void dfs(vector<int>& candidates, int i, int sum, int target){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        
        if(i == candidates.size() || sum > target) return;
        
        for(int j = i + 1; j < candidates.size(); j++){
            if(candidates[j] != candidates[i]){
                dfs(candidates, j, sum, target);
                break;
            }
        }
        
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, sum + candidates[i], target);
        path.pop_back();
        
    }
};