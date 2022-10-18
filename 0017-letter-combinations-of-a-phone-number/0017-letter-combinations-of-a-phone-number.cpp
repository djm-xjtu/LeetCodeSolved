class Solution {
public:
    vector<string> ans;
    unordered_map<int, string> h;
    void dfs(string digits, string temp, int u){
        int n = digits.size();
        int idx = digits[u] - '0';
        if(u == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < h[idx].size(); i++){
            dfs(digits, temp + h[idx][i], u + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        h[2] = "abc", h[3] = "def", h[4] = "ghi";
        h[5] = "jkl", h[6] = "mno", h[7] = "pqrs";
        h[8] = "tuv", h[9] = "wxyz";
        dfs(digits, "", 0);
        return ans;
    }
};