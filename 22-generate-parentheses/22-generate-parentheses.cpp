class Solution {
public:
    vector<string> path;
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return path;
    }
    void dfs(int l, int r, int n, string str){
        if(l == n && r == n){
            path.push_back(str);
        }
        if(l < n) dfs(l+1, r, n, str + "(");
        if(l > r) dfs(l, r + 1, n, str + ")");
    }
};