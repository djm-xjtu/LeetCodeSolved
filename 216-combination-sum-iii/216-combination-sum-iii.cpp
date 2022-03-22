class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(0, k, 1, 0, n);
        return ans;
    }
    void dfs(int count, int k, int i, int sum, int n){
        if(sum == n && count == k){
            ans.push_back(path);
            return;
        }
        if(i > 9 || count == k || sum > n) return;
        
        for(int j = i; j < 10; j++){
            path.push_back(j);
            dfs(count + 1, k, j + 1, sum + j, n);
            path.pop_back();
        }
    }
};