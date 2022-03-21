class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 0, n, 0, k);
        return ans;
    }
    
    void dfs(int i, int sum, int target, int count, int k){
        if(sum > target) return;
        if(k == count){
            if(sum == target) ans.push_back(path);
            return;
        }
        for(int j = i; j < 10; j++){
            path.push_back(j);
            dfs(j + 1, sum + j, target, count + 1, k);
            path.pop_back();
        }
    }
};