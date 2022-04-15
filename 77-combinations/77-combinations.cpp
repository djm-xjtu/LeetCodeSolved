class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        dfs(0, k, n, 1);
        return ans;
    }
    void dfs(int t, int k, int n, int idx){
        if(t == k){
            ans.push_back(path);
            return;
        }
        for(int i = idx; i <= n; i++){
            path.push_back(i);
            dfs(t + 1, k, n, i + 1);
            path.pop_back();
        }
    }
};