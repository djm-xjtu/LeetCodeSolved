class Solution {
public:
    vector<string> ans;
    unordered_map<int, vector<int>> dp;
    void dfs(string s, vector<string>& wordDict, int idx, int n, string t){
        if(idx == n){
            t.pop_back();
            ans.push_back(t);
            return;
        }
        if(!dp.count(idx)) return;
        for(int j = 0; j < dp[idx].size(); j++){
            t += s.substr(idx, dp[idx][j] - idx + 1);
            t += " ";
            dfs(s, wordDict, dp[idx][j] + 1, n, t);
            for(int k = 0; k < dp[idx][j] - idx + 2; k++) t.pop_back();
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        string t = "";
        for(int j = 0; j < wordDict.size(); j++){
            string word = wordDict[j];
            if(word.size() > n) continue;
            for(int i = 0; i <= n - word.size(); i++){ 
                if(s.substr(i, word.size()) == word) dp[i].push_back(i + word.size() - 1);
            }
        }
        dfs(s, wordDict, 0, n, t);
        return ans;
    }
};