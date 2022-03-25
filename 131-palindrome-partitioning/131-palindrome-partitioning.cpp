class Solution {
public:
    vector<vector<int>> dp; // i ~ j是不是回文串
    vector<vector<string>> ans;
    vector<string> path;
    int n;
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i++){
            dp[i][i] = 1;
            dp[i-1][i] = (s[i-1] == s[i]) ? 1 : 0;
        }
        
        for(int len = 2; len < n; len++){
            for(int i = 0; i + len < n; i++){
                int j = i + len;
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        dfs(s, 0);
        return ans;
    }
    
    void dfs(string s, int pos){
        if(pos == n){
            ans.push_back(path);
            return;
        }
        for(int i = pos; i < n; i++){
            if(dp[pos][i]){
                path.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }
};